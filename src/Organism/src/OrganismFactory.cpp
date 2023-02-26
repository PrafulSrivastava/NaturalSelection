#include "OrganismFactory.hpp"
#include "Utility.hpp"
#include <utility>

namespace SmartEvolution::Organism
{

    Organism OrganismFactory::getOrganism(std::shared_ptr<Common::Entity> &&entity, sf::Vector2f &&pos)
    {
        return Organism(std::move(entity), std::move(pos));
    }

    Organism OrganismFactory::getOrganism(std::shared_ptr<Common::Entity> &&entity)
    {
        return getOrganism(std::forward<decltype(entity)>(entity),
                           sf::Vector2f(Common::Utility::getRandomNumberInRange(0, Common::Width),
                                        Common::Utility::getRandomNumberInRange(0, Common::Height)));
    }
}
