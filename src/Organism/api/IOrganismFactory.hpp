#ifndef IORGANISM_FACTORY_HPP
#define IORGANISM_FACTORY_HPP

#include "Organism.hpp"

namespace SmartEvolution::Organism
{
    class IOrganismFactory
    {
    public:
        IOrganismFactory() = default;
        virtual ~IOrganismFactory() = default;

        virtual std::shared_ptr<Organism> getOrganism(std::shared_ptr<Common::Entity> &&entity, sf::Vector2f &&pos) = 0;
        virtual std::shared_ptr<Organism> getOrganism(std::shared_ptr<Common::Entity> &&entity) = 0;
    };
}

#endif