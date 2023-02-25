#include "OrganismFactory.hpp"
#include "Utility.hpp"
#include <utility>

namespace SmartEvolution::Organism
{

    std::shared_ptr<Organism> OrganismFactory::getOrganism(std::shared_ptr<Common::Entity> &&entity, sf::Vector2f &&pos)
    {
        return std::make_shared<Organism>(std::move(entity), std::move(pos));
    }

    std::shared_ptr<Organism> OrganismFactory::getOrganism(std::shared_ptr<Common::Entity> &&entity)
    {
        return getOrganism(std::forward<decltype(entity)>(entity), sf::Vector2f(Common::Utility::getRandomNumberInRange(0, Common::Width), Common::Utility::getRandomNumberInRange(0, Common::Height)));
    }
}
