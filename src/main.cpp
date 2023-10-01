#include "MaxFunction.hpp"

int main(int argc, char* argv[])
{
    genetic_algorithm::CoreSettings core_settings;
    core_settings.population_size = 20;
    core_settings.num_genomes_value = 1;
    core_settings.max_generations = 55000;

    genetic_algorithm::MaxFunction max_function(core_settings);
    const bool INITIALIZE_GENOME_VALUES = false;
    std::vector<double> initial_genomes_values = {4.1};
    max_function.initializeGenomesValues(initial_genomes_values);
    max_function.initialize(INITIALIZE_GENOME_VALUES);
    max_function.run();

    // genetic_algorithm::GACore ga_core(core_settings);
    // const bool INITIALIZE_GENOME_VALUES = false;
    // std::vector<double> initial_genomes_values = {3,2};
    // ga_core.initializeGenomesValues(initial_genomes_values);
    // ga_core.initialize(INITIALIZE_GENOME_VALUES);
    // ga_core.run();
}