#ifndef UTILITY_CLASSES_HPP
#define UTILITY_CLASSES_HPP

namespace genetic_algorithm
{

/**
 * @brief Essential setting used to execute the genetic algorithm
 * 
 */
struct CoreSettings
{   
    //! number of genomes in the population.
    int population_size;

    //! number of genome values inside each genome.
    int num_genomes_value;

    //! Maximum number of generation, after this number
    //! the algorithm stops.
    int max_generations;
};

}

#endif