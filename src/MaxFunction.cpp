#include "MaxFunction.hpp"

namespace genetic_algorithm
{

MaxFunction::MaxFunction(const CoreSettings &core_settings): GACore(core_settings)
{
}

double MaxFunction::evaluateCostFunction(const std::vector<double> &values)
{
    //double x_square =  std::pow(values.at(0), 2); 
    
    double x = values.at(0);
    //double x_square = -std::pow(x,4) + 20*std::pow(x,3) - 150*std::pow(x,2) + 500*x;
    double x_square = -std::pow(x-2, 2);
    if(x > 500)
    {
        x_square /= 1000;
    }
    return x_square;

}

}
