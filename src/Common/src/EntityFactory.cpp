#include "EntityFactory.hpp"
#include "Utility.hpp"

namespace SmartEvolution::Common
{
    std::shared_ptr<Entity> EntityFactory::getEntity(const GenomeSequence &sequence)
    {
        if (m_entites[sequence] == nullptr)
        {
            m_entites[sequence] = std::make_shared<Entity>(Utility::getFreshColor(sf::Color::Green), OrganismSize, sequence);
        }

        return m_entites[sequence];
    }
}