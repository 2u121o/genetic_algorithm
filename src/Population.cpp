#include "Population.hpp"

namespace genetic_algorithm
{

Population::Population(std::vector<std::shared_ptr<Genome>> &genomes): genomes_(genomes),
                                                      generation_num_(0)
{
    std::cout << "[Population] created population give the set of genomes" << std::endl;
}

Population::Population(const int population_size, const int num_values): generation_num_(0)
{
    genomes_.resize(population_size);
    for(int i=0; i<population_size; i++)
    {
        std::shared_ptr<Genome> p_genomes = std::make_shared<Genome>(num_values);
        genomes_.at(i) = p_genomes;
    }
}

void Population::sort()
{
    std::sort(genomes_.begin(), genomes_.end(), [](const std::shared_ptr<Genome>& a, const std::shared_ptr<Genome>& b) {return *a > *b;});
}

void Population::createNextGeneration()
{

    if(generation_num_ == 0)
    {
        sort();
    }
    std::vector<std::shared_ptr<Genome>> next_genomes = genomes_;
    int population_size = static_cast<int>(genomes_.size());
    for(int i=0; i<population_size/2; i++)
    {
        Genome genome_a = *genomes_.at(i); 
        Genome genome_b = *genomes_.at(population_size -1 - i); 
        std::shared_ptr<Genome> p_next_genome = std::make_shared<Genome>(genome_a * genome_b);
        p_next_genome->mutation();
        next_genomes.at(population_size/2 + i) = p_next_genome;
    }
    genomes_ = next_genomes;
    sort();
    generation_num_++;
}

void Population::setPopulation(const std::vector<std::shared_ptr<Genome>> &genomes)
{
    genomes_ = genomes;
}

const std::vector<std::shared_ptr<Genome>>& Population::getPopulation() const
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
    return *(genomes_.at(0));
}

}//genetic_algorithm