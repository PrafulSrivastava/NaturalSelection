#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include <memory>
#include "Entity.hpp"
#include "CommonTypes.hpp"

namespace SmartEvolution::Organism
{

    struct Organism
    {
        Organism(std::shared_ptr<Common::Entity> &&entity, sf::Vector2f &&pos)
            : m_entity(std::move(entity)),
              m_position(std::move(pos))
        {
            std::cout << __func__ << std::endl;
        }

        ~Organism()
        {
            m_entity.reset();
        }

        std::shared_ptr<Common::Entity> m_entity;
        sf::Vector2f m_position;
    };
}

#endif