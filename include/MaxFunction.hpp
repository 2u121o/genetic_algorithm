#ifndef MAX_FUNCTION_HPP
#define MAX_FUNCTION_HPP

#include "utiliy_classes.hpp"
#include "GACore.hpp"

namespace genetic_algorithm
{

class MaxFunction : public GACore
{
    public:
        MaxFunction(const CoreSettings &core_settings);

    private:
      
        double evaluateCostFunction(const std::vector<double> &values) override;

};

}// genetic_algorithm



#endif