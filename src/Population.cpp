#include "Population.hpp"

namespace genetic_algorithm
{

Population::Population(): generation_num_(0)
{

}

Population::Population(std::shared_ptr<Genome> &genomes): genomes_(genomes),
                                                      generation_num_(0)
{
    std::cout << "[Population] creaed population give the set of genomes" << std::endl;
}

Population::Population(const int population_size, const int num_values): generation_num_(0)
{
    genomes_.resize(population_size);
    for(int i=0; i<population_size; i++)
    {
        Genome genome(num_values);
        genomes_.at(i) = genome;
    }
}

void Population::sort()
{
    std::sort(genomes_.begin(), genomes_.end(), std::greater<Genome>());
}

void Population::createNextGeneration()
{
    std::cout << "[Population] create next generatoion: " << generation_num_ << std::endl;
    if(generation_num_ == 0)
    {
        sort();
    }
    std::vector<std::shared_ptr<Genome>> next_genomes = genomes_;
    int pupulation_size = static_cast<int>(genomes_.size());
    for(int i=0; i<pupulation_size/2; i++)
    {
        Genome genome_a = genomes_.at(i); 
        Genome genome_b = genomes_.at(pupulation_size -1 - i); 
        Genome next_genome(genome_a * genome_b);
        next_genome.mutation();
        next_genomes.at(pupulation_size/2 + i) = next_genome;
    }
    genomes_ = next_genomes;
    sort();
    for(int i=0; i<genomes_.size(); i++)
    {
        std::cout << "[Population] genome fitness: " << genomes_.at(i).getFitness() << std::endl; 
    }
    std::cout  << std::endl; 
    generation_num_++;
}

void Population::setPopulation(const std::shared_ptr<Genome> &genomes)
{
    genomes_ = genomes;
}

const std::shared_ptr<Genome>& Population::getPopulation() const
{
    return genomes_;
}

int Population::getGenerationNum() const
{
    return generation_num_;
}

void Population::increaseGenerationNumber()
{
    generation_num_++;
}

Genome& Population::getBestGenome()
{
    return genomes_.at(0);
}

}//genetic_algorithm