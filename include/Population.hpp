#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#include "Genome.hpp"

namespace genetic_algorithm
{

class Population
{
    public:
        Population();
        Population(std::vector<Genome> &genomes);
        Population(const int population_size, const int num_values);

        void createNextGeneration();
        void sort();

        void setPopulation(const std::vector<Genome> &genomes);
        const std::vector<Genome>& getPopulation() const;

        int getGenerationNum() const;
        void increaseGenerationNumber();

        Genome& getBestGenome() ;

    private:
        std::vector<Genome> genomes_;
        int generation_num_;

};


} // genetic_algorithm 

#endif