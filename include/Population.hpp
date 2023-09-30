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
        Population();
        Population(std::vector<std::shared_ptr<Genome>> &genomes);
        Population(const int population_size, const int num_values);

        void createNextGeneration();
        void sort();

        void setPopulation(const std::vector<std::shared_ptr<Genome>> &genomes);
        const std::vector<std::shared_ptr<Genome>>& getPopulation() const;

        int getGenerationNum() const;
        void increaseGenerationNumber();

        Genome& getBestGenome() ;

    private:
        std::vector<std::shared_ptr<Genome>> genomes_;
        int generation_num_;

};


} // genetic_algorithm 

#endif