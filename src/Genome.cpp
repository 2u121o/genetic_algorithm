#include "Genome.hpp"

namespace genetic_algorithm
{

Genome::Genome(const int num_values, const bool initialie_values=true): age_(0), 
                                                                        fitness_(0), 
                                                                        num_values_(num_values),
                                                                        uniform_int_distribution_(0,1),
                                                                        uniform_real_distribution_(0.0,1.0)
                                    {
    initialize(initialie_values);
}

void Genome::initialize(const bool initialie_values)
{
    std::random_device random_device;
    generator_.seed(random_device);

    if(initialie_values)
    {
        values_.resize(num_values_);
        for(int i=0; i<num_values_; i++)
        {
            double random_number = uniform_real_distribution_(generator_);
            values_.at(i) = random_number * 10.0;
        }
    }
}

void Genome::setFitness(const double fitness)
{
    fitness_ = fitness;
}

double Genome::getFitness() const
{
    return fitness_;
}

void Genome::mutation()
{
    double random_number = uniform_real_distribution_(generator_);
    if(random_number < MUTATION_PROBABILITY)
    {
        int mutation_index = static_cast<int>((random_number*100) % 10);
        int exchange_index = static_cast<int>((random_number*1000) % 10);
        if(mutation_index >= num_values_)
        {
            mutation_index = num_values_-1;
        }
        if(exchange_index >= num_values_)
        {
            exchange_index = num_values_-1;
        }
        else if(exchange_index == mutation_index)
        {
            exchange_index--;
        }
        values_.at(mutation_index) = values_.at(exchange_index);
    }
}

void Genome::setValues(const std::vector<double> values)
{
    values_ = values;
}

const std::vector<double>& Genome::getValues() const
{
    return values_;
}

Genome operator*(const Genome& genome) const
{
    Genome genome_result = genome;
    for(int i=0; i<num_values_; i++)
    {
        bool crossover_decision = static_cast<bool>(uniform_int_distribution_(generator_));
        if(crossover_decision)
        {
            genome_result.at(i) = values_(i);
        }
    }
 
    return genome_result;
}

bool operator<(const Genome& genome) const
{
    fitness_ < genome.getFitness();
}

bool operator>(const Genome& genome) const
{
    fitness_ > genome.getFitness();
}

std::ostream& operator<<(std::ostream& output, const Genome genome)
{
    for(int i=0; i<num_values_; i++)
    {
        output << genome.values_.at(i) << std::endl;
    }
    output << std::endl;
}

} // genetic_algorithm
