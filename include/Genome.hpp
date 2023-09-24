#ifndef GENOME_HPP
#define GENOME_HPP

#include <iostream>
#include <vector>
#include <random>

#include <Eigen/Dense>

namespace genetic_algorithm
{

class Genome
{
    public:
        Genome(const int num_values, const bool initialie_values=false);

        void setFitness(const double fitness);

        double getFitness() const;

        void mutation();

        void setValues(const std::vector<double> values);
        const std::vector<double>& getValues() const;

        Genome operator*(const Genome& genome) const;
        bool operator<(const Genome& genome) const;
        bool operator>(const Genome& genome) const;

        friend std::ostream& operator<<(std::ostream& output, const Genome genome);

    private:
        
        int age_;
        double fitness_;
        int num_values_;
        std::vector<double> values_;

        std::uniform_int_distribution<int> uniform_int_distribution_;
        std::uniform_real_distribution<double> uniform_real_distribution_;
        std::mt19937 generator_;

        const double MUTATION_PROBABILITY = 0.4;

        void initialize(const bool initialie_values);

};

} //genetic_algorithm

#endif