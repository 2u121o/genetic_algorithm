#ifndef GA_CORE_HPP
#define GA_CORE_HPP

#include <iostream>
#include <memory>

#include "utiliy_classes.hpp"
#include "Population.hpp"
#include "Genome.hpp"

namespace genetic_algorithm
{

class GACore
{
    public:
        /**
         * @brief Construct a new genetic algorithm core using the core settings.
         * 
         * @param core_settings is a struc representing the setting necessary to run
         *                      the genetic algorithm.
         */
        GACore(const CoreSettings &core_settings);
        
        /**
         * @brief Creates and initializes the population with genomes.
         * 
         * @param initialize_values flag to check whether the values of the genomes are 
         *                          initialized or not.
         */
        void initialize(const bool initialize_values=false);

        /**
         * @brief Run the genetic algorithm core for the number of generations specified 
         *        in the core settings.
         * 
         */
        void run();

        /**
         * @brief Initializes the genomes with user defined values.
         * 
         * @param initial_genomes_value is a num_values-dimensional vector containing the initialization
         *                              values for the genomes.
         */
        void initializeGenomesValues(const std::vector<double> &initial_genomes_value);

    private:
        //! Setting used to run the genetic algorithm.
        CoreSettings core_settings_;

        //! Population of genomes used in the genetic algorithm.
        Population population_;

    protected:

        //! is a num_values-dimensional vector containing the initialization values for the genomes.
        std::vector<double> initial_genomes_value_;

        /**
         * @brief Virtual function that must be implemented for the specific problem in order to 
         *        generate the correct fitness values. This will be evaluated at each iteration 
         *        for each genomes in the genetic algorithm core in order to compute the fitness of 
         *        each genome in the population.
         * 
         * @param values is a num_values-dimensional vector containing the values in the genome. i.e.,
         *               the parameters to be optimized during the execution of the algorithm.
         * @return return the fitness of the specific genome.
         */
        virtual double evaluateCostFunction(const std::vector<double> &values) = 0;

};

}

#endif