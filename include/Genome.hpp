#ifndef GENOME_HPP
#define GENOME_HPP

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

namespace genetic_algorithm
{

class Genome
{
    public:

        /**
         * @brief Construct a new Genome object without initializing the genomes 
         *        values.
         * 
         */
        Genome();

        /**
         * @brief Copy constructor. 
         * 
         * @param genome 
         */
        Genome(const Genome &genome);

        /**
         * @brief Construct a new Genome object and initialize the genomes values
         *        using random values in case is specified by the user, otherwise
         *        it does not initialize the values. 
         * 
         * @param num_values is the number of parameters inside the genome.
         * @param initialize_values is a flag to specify whether the values are initialized
         *                          with random values or not initialized at all. 
         */
        Genome(const int num_values, const bool initialize_values=false);

        /**
         * @brief Set the genome fitness value.
         * 
         * @param fitness is the fitness value. 
         */
        void setFitness(const double fitness);

        /**
         * @brief Get the fitness value.
         * 
         * @return return the genome fitness. 
         */
        double getFitness() const;

        /**
         * @brief Performs the mutation on the genomes. The mutation is performed taking a random
         *        value in the values vector and randomly adding or subtracting a random number.
         * 
         */
        void mutation();

        /**
         * @brief Set the values vector.
         * 
         * @param values is a vector of doubles containing the values of the genome.
         */
        void setValues(const std::vector<double> values);

        /**
         * @brief Get the values vector.
         * 
         * @return return a vector of double containing the genomes values.
         */
        const std::vector<double>& getValues() const;

        /**
         * @brief Get the number of values of the genome.
         * 
         * @return return the number of values of the genome. 
         */
        int getNumValues() const;

        /**
         * @brief Get the genomes age.
         * 
         * @return return an int representing the genome age. 
         */
        int getAge() const;

        /**
         * @brief Crossover operator.
         * 
         * @param genome 
         * @return Genome 
         */
        Genome operator*(const Genome& genome);
        
        /**
         * @brief Compare if the current genome is smaller then the genome in the argument
         *        function based on their fitness.
         * 
         * @param genome 
         * @return true 
         * @return false 
         */
        bool operator<(const Genome& genome) const;

        /**
         * @brief Compare if the current genome is grater then the genome in the argument
         *        function based on their fitness.
         * 
         * @param genome 
         * @return true 
         * @return false 
         */
        bool operator>(const Genome& genome) const;

        /**
         * @brief Assignment operator to initialize a genome with another genome.
         * 
         * @param genome 
         * @return Genome& 
         */
        Genome& operator=(const Genome& genome);

        /**
         * @brief Prints the values and the fitness of the genome.
         * 
         * @param output 
         * @param genome 
         * @return std::ostream& 
         */
        friend std::ostream& operator<<(std::ostream& output, const Genome genome);

    private:
        
        //! Represents the number of iteration this genome is alive.
        int age_;

        //! Represents the goodness of this genome for the given problem.
        double fitness_;

        //! Represents the number of values inside the vector values. i.e., the number
        //! of variables in the problem for each genome.
        int num_values_;

        //! num_values_-dimensional vector containing the values of the genome. The values
        //! are the variables of the problem. i.e., the parameters that are adjusted during 
        //! the evolution.
        std::vector<double> values_;

        //! Uniform int distribution used for the crossover decision.
        std::uniform_int_distribution<int> uniform_int_distribution_;

        //! Uniform real distribution used in the mutation function.
        std::uniform_real_distribution<double> uniform_real_distribution_;

        //! Random number generator.
        std::mt19937 generator_;

        //! Probability that the genomes mutate. If the random number is lower then this value
        //! the genomes mutate otherwise it does not mutate.
        const double MUTATION_PROBABILITY = 0.2;

        /**
         * @brief Initializes the vector values with random values.
         * 
         */
        void initialize();

};

} //genetic_algorithm

#endif