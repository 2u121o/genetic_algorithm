#include "GACore.hpp"

namespace genetic_algorithm
{

GACore::GACore(const CoreSettings &core_settings): core_settings_(core_settings)
{

}

void GACore::initialize(const bool initialie_values)
{
    std::vector<Genome> genomes(core_settings_.population_size);
    for(int i=0; i<core_settings_.population_size; )
    {
        Genome genome(core_settings_.num_genoms_value, initialie_values);
        if(!initialie_values && initial_genoms_value_.size() == core_settings_.num_genoms_value)
        {
            genome.setValues(initial_genoms_value_);
        }
        else
        {
            //TODO: throw an exception
            std::cout << "[GACore] since the genoms values have not been initialized with defauls values it is neccessary" 
                      <<           "to set the initial values" << std::endl;
        }
        genomes.at(i) = genome;
    }
    population_.setPopulation(genomes);
}

void GACore::run()
{
    int iteration_num = population_.getGenerationNum();
    for(; iteration_num<core_settings_.max_generations; 
          population_.increaseGenerationNumber()
        )
    {
        for(Genome genome : population_.getPopulation())
        {
            double fitness = evaluateCostFunction(genome.getValues());
            genome.setFitness(fitness);
        }

        population_.createNextGeneration();
    }

    std::cout << "[GACore] genetic algorithm terminates. The best genome has the following values:\n" 
              << population_.getBestGenome() << std::endl;
}

}// genetic_algorithm