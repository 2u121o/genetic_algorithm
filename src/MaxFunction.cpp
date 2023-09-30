#include "MaxFunction.hpp"

namespace genetic_algorithm
{

MaxFunction::MaxFunction(const CoreSettings &core_settings): GACore(core_settings)
{
}

double MaxFunction::evaluateCostFunction(const std::vector<double> &values)
{   
    double x = values.at(0);
    //double fitness = -std::pow(x,4) + 20*std::pow(x,3) - 150*std::pow(x,2) + 500*x;
    double fitness = -std::pow(x,4) - 8*std::pow(x,3) + 18*x;
    //fitness = -fitness;
    //double x_square = -std::pow(x-2, 2);
    if(x > 10 || x < 0)
    {
        fitness /= 1000;
    }
    return fitness;

}

}
