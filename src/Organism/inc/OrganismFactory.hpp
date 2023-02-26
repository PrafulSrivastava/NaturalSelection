#ifndef ORGANISM_FACTORY_HPP
#define ORGANISM_FACTORY_HPP

#include "IOrganismFactory.hpp"

namespace SmartEvolution::Organism
{
    class OrganismFactory : public IOrganismFactory
    {
    public:
        OrganismFactory() = default;
        ~OrganismFactory() override = default;

        OrganismFactory(const OrganismFactory &) = delete;
        OrganismFactory &operator=(const OrganismFactory &) = delete;
        OrganismFactory(OrganismFactory &&) = delete;
        OrganismFactory &operator=(OrganismFactory &&) = delete;

        Organism getOrganism(std::shared_ptr<Common::Entity> &&entity, sf::Vector2f &&pos) override;
        Organism getOrganism(std::shared_ptr<Common::Entity> &&entity) override;
    };
}

#endif