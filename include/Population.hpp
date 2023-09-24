#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostram>
#include <vector>

#include "Genome.hpp"

namespace genetic_algorithm
{

class Population
{
    public:
        Population();
        Population(std::vector<Genome> &genomes);
        Population(const int population_size);

        void createNextGeneration();
        void sort();

        void setPopulation(const std::vector<Genome> &genomes);
        const std::vector<Genome>& getPopulation() const;

        int getGenerationNum() const;
        void increaseGenerationNumber();

        Genome& getBestGenome() const;

    private:
        std::vector<Genome> genomes_;
        int generation_num_;

};


} // genetic_algorithm 

#endif