#include "MaxFunction.hpp"

namespace genetic_algorithm
{

MaxFunction::MaxFunction(const CoreSettings &core_settings): GACore(core_settings)
{
}

double MaxFunction::evaluateCostFunction(const std::vector<double> &values)
{
    return std::pow(values.at(0), 2); 
}


}

