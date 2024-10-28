#include <ExaMPM_BoundaryConditions.hpp>
#include <ExaMPM_Solver.hpp>

#include <Cabana_Core.hpp>

#include <Cabana_Grid.hpp>

#include <Kokkos_Core.hpp>

#include <mpi.h>

#include <array>
#include <cmath>

//---------------------------------------------------------------------------//
// Create the problem setup. The initial geometry is a static water column
// from [0,0.4] in X, [0,0.6] in Z, with the entire Y domain filled.
struct ParticleInitFunc
{
    double _volume;
    double _mass;

    ParticleInitFunc( const double cell_size, const int ppc,
                      const double density )
        : _volume( cell_size * cell_size * cell_size / ( ppc * ppc * ppc ) )
        , _mass( _volume * density )
    {
    }

    template <class ParticleType>
    KOKKOS_INLINE_FUNCTION bool operator()( const double x[3],
                                            ParticleType& p ) const
    {
        if ( 0.0 <= x[0] && x[0] <= 0.4 && 0.0 <= x[1] && x[1] <= 1.0 &&
             0.0 <= x[2] && x[2] <= 0.6 )
        {
            // Affine matrix.
            for ( int d0 = 0; d0 < 3; ++d0 )
                for ( int d1 = 0; d1 < 3; ++d1 )
                    Cabana::get<0>( p, d0, d1 ) = 0.0;

            // Velocity
            for ( int d = 0; d < 3; ++d )
                Cabana::get<1>( p, d ) = 0.0;

            // Position
            for ( int d = 0; d < 3; ++d )
                Cabana::get<2>( p, d ) = x[d];

            // Mass
            Cabana::get<3>( p ) = _mass;

            // Volume
            Cabana::get<4>( p ) = _volume;

            // Deformation gradient determinant.
            Cabana::get<5>( p ) = 1.0;

            return true;
        }

        return false;
    }
};

//---------------------------------------------------------------------------//
void damBreak( const double cell_size, const int ppc, const int halo_size,
               const double delta_t, const double t_final, const int write_freq,
               const std::string& exec_space )
{
    // The dam break domain is in a box on [0,1] in each dimension.
    Kokkos::Array<double, 6> global_box = { 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 };

    // Compute the number of cells in each direction. The user input must
    // squarely divide the domain.
    std::array<int, 3> global_num_cell = {
        static_cast<int>( 1.0 / cell_size ),
        static_cast<int>( 1.0 / cell_size ),
        static_cast<int>( 1.0 / cell_size ) };

    // This will look like a 2D problem so make the Y direction periodic.
    std::array<bool, 3> periodic = { false, false, false };

    // Due to the 2D nature of the problem we will only partition in Y. The
    // behavior of the fluid will be to largely just run out in X and Z with
    // little movement in Y.
    int comm_size;
    MPI_Comm_size( MPI_COMM_WORLD, &comm_size );
    std::array<int, 3> ranks_per_dim = { 1, comm_size, 1 };
    Cabana::Grid::ManualBlockPartitioner<3> partitioner( ranks_per_dim );

    // Material properties.
    double bulk_modulus = 1.0e5;
    double density = 1.0e3;
    double gamma = 7.0;
    double kappa = 100.0;

    // Gravity pulls down in z.
    double gravity = 9.81;

    // Free slip conditions (alternative: NO_SLIP)
    ExaMPM::BoundaryCondition bc;
    bc.boundary[0] = ExaMPM::BoundaryType::FREE_SLIP;
    bc.boundary[1] = ExaMPM::BoundaryType::FREE_SLIP;
    bc.boundary[2] = ExaMPM::BoundaryType::FREE_SLIP;
    bc.boundary[3] = ExaMPM::BoundaryType::FREE_SLIP;
    bc.boundary[4] = ExaMPM::BoundaryType::FREE_SLIP;
    bc.boundary[5] = ExaMPM::BoundaryType::FREE_SLIP;

    // Solve the problem.
    auto solver = ExaMPM::createSolver(
        exec_space, MPI_COMM_WORLD, global_box, global_num_cell, periodic,
        partitioner, halo_size, ParticleInitFunc( cell_size, ppc, density ),
        ppc, bulk_modulus, density, gamma, kappa, delta_t, gravity, bc );
    solver->solve( t_final, write_freq );
}

//---------------------------------------------------------------------------//
int loop( )
{
    MPI_Init( NULL, NULL );

    Kokkos::initialize();


    // cell size
    double cell_size = 0.05 ;

    // particles per cell in a dimension
    int ppc = 2;

    // number of halo cells.
    int halo_size = 0;

    // time step size.
    double delta_t = 0.001;

    // end time.
    double t_final = 0.1;

    // write frequency
    int write_freq = 10;

    // execution space
    std::string exec_space = "serial";

    // run the problem.
    damBreak( cell_size, ppc, halo_size, delta_t, t_final, write_freq,
              exec_space );

    Kokkos::finalize();

    MPI_Finalize();

    return 0;
}

//---------------------------------------------------------------------------//