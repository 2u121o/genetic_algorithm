#include "Genome.hpp"

namespace genetic_algorithm
{

Genome::Genome(): age_(0),
                  fitness_(0),
                  uniform_int_distribution_(0,1),
                  uniform_real_distribution_(0.0,1.0)
{

}

Genome::Genome(const Genome &genome): uniform_int_distribution_(0,1),
                                      uniform_real_distribution_(0.0,1.0)
{
    age_ = genome.getAge();
    fitness_ = genome.getFitness();
    num_values_ = genome.getNumValues();
    values_ = genome.getValues();
}

Genome::Genome(const int num_values, const bool initialize_values): age_(0), 
                                                                   fitness_(0), 
                                                                   num_values_(num_values),
                                                                   uniform_int_distribution_(0,1),
                                                                   uniform_real_distribution_(0.0,1.0)
{
    if(initialize_values)
    {
        initialize();
    }
}

void Genome::initialize()
{

   
    values_.resize(num_values_);
    for(int i=0; i<num_values_; i++)
    {
        double random_number = uniform_real_distribution_(generator_);
        values_.at(i) = random_number * 10.0;
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
    auto current_time = std::chrono::system_clock::now();
    auto current_time_nanoseconds = std::chrono::time_point_cast<std::chrono::nanoseconds>(current_time);
    auto current_time_since_epoch = current_time_nanoseconds.time_since_epoch();
    generator_.seed(current_time_since_epoch.count());
    double random_number = uniform_real_distribution_(generator_);
    double random_number_sign_decision = uniform_real_distribution_(generator_);

    if(random_number < MUTATION_PROBABILITY)
    {

        int mutation_index = static_cast<int>((random_number*100.0)) % 10;
        if(mutation_index >= num_values_)
        {
            mutation_index = num_values_-1;
        }

        if(random_number_sign_decision>0.5)
        {
            values_.at(mutation_index) = values_.at(mutation_index) + random_number;
        }
        else
        {
            values_.at(mutation_index) = values_.at(mutation_index) - random_number;
        }
        
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
        output << "Value_" << i << ": " << genome.values_.at(i) << std::endl;
    }
    output << "Fitness: " << genome.getFitness();
    return output;
}

} // genetic_algorithm
