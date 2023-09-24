#ifndef GACORE_HPP
#define GACORE_HPP

#include <iostream>

#include "utiliy_classes.hpp"
#include "Population.hpp"
#include "Genome.hpp"

namespace genetic_algorithm
{

class GACore
{
    public:
        GACore(const CoreSettings &core_settings);
        
        void initialize(const bool initialie_values=false);
        void run();

    private:
        CoreSettings core_settings_;
        Population population_;

    protected:
        std::vector<double> initial_genoms_value_;

        virtual double evaluateCostFunction(const std::vector<double> &values) = 0;

};

}

#endif