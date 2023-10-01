#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#include "Genome.hpp"

namespace genetic_algorithm
{

class Population
{
    public:

        /**
         * @brief Construct a new population object with default values.
         * 
         */
        Population() = default;

        /**
         * @brief Construct a new Population object and populates it with genomes
         *        defined by the user.
         * 
         * @param genomes is a vector containing pointer to the genomes that composes 
         *                the population.
         */
        Population(std::vector<std::shared_ptr<Genome>> &genomes);

        /**
         * @brief Construct a new Population object and populates it with not initialized
         *        genomes.
         * 
         * @param population_size is the dimension of the population in terms of number of genomes.
         * @param num_values is the number of values inside each genomes. i.e., the parameters to 
         *                   be optimized.
         */
        Population(const int population_size, const int num_values);

        /**
         * @brief Generated the next generation of genomes. First the genomes in the population
         *        are sorted in a descending order based on their fitness and then the crossover
         *        and mutation is applied.
         * 
         */
        void createNextGeneration();

        /**
         * @brief Sort the genomes in the genomes vector in a descending order based on their fitness.
         * 
         */
        void sort();

        /**
         * @brief Set the Population with a user defined vector of pointer to genomes.
         * 
         * @param genomes is a vector of genome pointers.
         */
        void setPopulation(const std::vector<std::shared_ptr<Genome>> &genomes);

        /**
         * @brief Get the pointers to the Genomes inside the population.
         * 
         * @return return a vector containing the pointers to the genomes inside the 
         *         population. 
         */
        const std::vector<std::shared_ptr<Genome>>& getPopulation() const;

        /**
         * @brief Get the current generation for this population.
         * 
         * @return return an integer representing the generation number.
         */
        int getGenerationNum() const;

        /**
         * @brief Increments the generation number by one.
         * 
         */
        void increaseGenerationNumber();

        /**
         * @brief Get the best genomes in the genomes vector. The genome that is considered
         *        the best is the one with the highest fitness. Since the genomes are sorted
         *        in a descending order based on their fitness inside the genomes vector, the 
         *        best genomes is the first genome in the vector.
         * 
         * @return return the best genome.
         */
        Genome& getBestGenome() ;

    private:

        //! population_size-dimensional vector containing pointers to genome.
        std::vector<std::shared_ptr<Genome>> genomes_;

        //! current generation number.
        int generation_num_;

};


} // genetic_algorithm 

#endif