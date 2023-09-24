#include "Genome.hpp"

namespace genetic_algorithm
{

Genome::Genome(): age_(0),
                  fitness_(0),
                  uniform_int_distribution_(0,1),
                  uniform_real_distribution_(0.0,1.0)
{

}

Genome::Genome(const int num_values, const bool initialie_values): age_(0), 
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
    generator_.seed(random_device());

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
        int mutation_index = static_cast<int>((random_number*100.0)) % 10;
        int exchange_index = static_cast<int>((random_number*1000.0)) % 10;
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

int Genome::getNumValues() const
{
    return num_values_;
}

int Genome::getAge() const
{
    return age_;
}

double* Genome::at(const int index)
{
    return &values_.at(index);
}

Genome Genome::operator*(const Genome& genome)
{
    Genome genome_result = genome;
    for(int i=0; i<num_values_; i++)
    {
        bool crossover_decision = static_cast<bool>(uniform_int_distribution_(generator_));
        if(crossover_decision)
        {
            values_.at(i) = genome.getValues().at(i);
        }
    }
 
    return genome_result;
}

bool Genome::operator<(const Genome& genome) const
{
    return fitness_ < genome.getFitness();
}

bool Genome::operator>(const Genome& genome) const
{
    return fitness_ > genome.getFitness();
}


Genome& Genome::operator=(const Genome& genome)
{
    if(this != &genome)
    {
        age_ = genome.getAge();
        fitness_ = genome.getFitness();
        num_values_ = genome.getNumValues();
        values_ = genome.getValues();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& output, const Genome genome)
{
    for(int i=0; i<genome.getNumValues(); i++)
    {
        output << genome.values_.at(i) << std::endl;
    }
    output << std::endl;
    return output;
}

} // genetic_algorithm
