#include "EntityFactory.hpp"
#include "Utility.hpp"

namespace SmartEvolution::Common
{
    std::shared_ptr<Entity> EntityFactory::getEntity(const EntityType &entityType, const GenomeSequence &sequence)
    {
        GenomeSequenceId id = sequence.to_string();
        auto color = sf::Color::Green;
        if (m_entites[id] == nullptr)
        {
            m_entites[id] = std::make_shared<LivingEntity>(Utility::getFreshColor(sf::Color::Blue), OrganismSize, id);
        }

        return m_entites[id];
    }

    std::shared_ptr<Entity> EntityFactory::getEntity(const EntityType &entityType)
    {
        GenomeSequenceId id = Common::Utility::translateEntityType(entityType);
        auto color = sf::Color::Green;
        if (m_entites[id] == nullptr)
        {
            switch (entityType)
            {
            case EntityType::Boundry:
                m_entites[id] = std::make_shared<NonLivingEntity>(Utility::getFreshColor(sf::Color::Red), BoundrySize);
                break;
            }
        }

        return m_entites[id];
    }
}