#include "GACore.hpp"

namespace genetic_algorithm
{

GACore::GACore(const CoreSettings &core_settings): core_settings_(core_settings)
{
    std::cout << "[GACore] constructed" << std::endl;
}

void GACore::initialize(const bool initialize_values)
{
    std::vector<std::shared_ptr<Genome>> genomes(core_settings_.population_size);
    for(int i=0; i<core_settings_.population_size; i++)
    {
        std::shared_ptr<Genome> p_genome = std::make_shared<Genome>(core_settings_.num_genomes_value, initialize_values);
        if(!initialize_values && initial_genomes_value_.size() == core_settings_.num_genomes_value)
        {
            
            p_genome->setValues(initial_genomes_value_);
        }
        else
        {
            //TODO: throw an exception
            std::cout << "[GACore] since the genomes values have not been initialized with defaults values it is necessary" 
                      <<           "to set the initial values" << std::endl;
        }
        genomes.at(i) = p_genome;
    }
    population_.setPopulation(genomes);
}

void GACore::run()
{
    
    for(int iteration_num = population_.getGenerationNum(); 
        iteration_num<core_settings_.max_generations; 
        population_.increaseGenerationNumber()
        )
    {
        for(std::shared_ptr<Genome> genome : population_.getPopulation())
        {   
            double fitness = evaluateCostFunction(genome->getValues());
            genome->setFitness(fitness);
        }

        population_.createNextGeneration();
        iteration_num = population_.getGenerationNum();
    }

    std::cout << "[GACore] genetic algorithm terminates. The best genome has the following values:\n" 
              << population_.getBestGenome() << std::endl;
}

void GACore::initializeGenomesValues(const std::vector<double> &initial_genomes_value)
{
    initial_genomes_value_ = initial_genomes_value;
}


double GACore::evaluateCostFunction(const std::vector<double> &values)
{
  return 1;
}

}// genetic_algorithm