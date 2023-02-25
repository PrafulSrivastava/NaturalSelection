#include <iostream>
#include "EntityFactory.hpp"
#include "OrganismFactory.hpp"

using namespace SmartEvolution::Common;
using namespace SmartEvolution::Organism;

void generateOrganisms()
{
    std::unique_ptr<IEntityFactory> entityFactory = std::make_unique<EntityFactory>();
    std::unique_ptr<IOrganismFactory> organismFactory = std::make_unique<OrganismFactory>();
    for (auto i = 0; i < 10; i++)
    {
        organismFactory->getOrganism(entityFactory->getEntity("Yes"));
    }
}

int main()
{
    generateOrganisms();
    return 0;
}