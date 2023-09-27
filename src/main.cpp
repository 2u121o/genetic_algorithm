#include "GACore.hpp"

int main(int argc, char* argv[])
{
    genetic_algorithm::CoreSettings core_settings;
    core_settings.population_size = 10;
    core_settings.num_genoms_value = 2;
    core_settings.max_generations = 10;

    genetic_algorithm::GACore ga_core(core_settings);
    const bool INITIALIZE_GENOM_VALUES = false;
    std::vector<double> initial_genomes_values = {3,2};
    ga_core.initializeGenomesValues(initial_genomes_values);
    ga_core.initialize(INITIALIZE_GENOM_VALUES);
    ga_core.run();
}