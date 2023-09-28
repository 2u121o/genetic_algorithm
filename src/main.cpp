#include "MaxFunction.hpp"

int main(int argc, char* argv[])
{
    genetic_algorithm::CoreSettings core_settings;
    core_settings.population_size = 10;
    core_settings.num_genoms_value = 1;
    core_settings.max_generations = 2;

    genetic_algorithm::MaxFunction max_function(core_settings);
    const bool INITIALIZE_GENOM_VALUES = false;
    std::vector<double> initial_genomes_values = {3};
    max_function.initializeGenomesValues(initial_genomes_values);
    max_function.initialize(INITIALIZE_GENOM_VALUES);
    max_function.run();

    // genetic_algorithm::GACore ga_core(core_settings);
    // const bool INITIALIZE_GENOM_VALUES = false;
    // std::vector<double> initial_genomes_values = {3,2};
    // ga_core.initializeGenomesValues(initial_genomes_values);
    // ga_core.initialize(INITIALIZE_GENOM_VALUES);
    // ga_core.run();
}