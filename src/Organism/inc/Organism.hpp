#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include <memory>
#include "Entity.hpp"
#include "IUnit.hpp"
#include "CommonTypes.hpp"

namespace SmartEvolution::Organism
{

    struct Organism : public Common::IUnit
    {
        Organism(std::shared_ptr<Common::Entity> &&entity, sf::Vector2f &&pos)
            : m_entity(std::move(entity))
        {
            setPosition(pos);
            setFillColor(m_entity->m_color);
            setRadius(m_entity->m_size);
            Common::Utility::setOriginToCenter(*this);
            std::cout << __func__ << " At: {" << getPosition().x << ", " << getPosition().y << "}" << std::endl;
        }

        ~Organism()
        {
            m_entity.reset();
        }

        void run()
        {
        }
        void update()
        {
        }
        void draw(sf::RenderWindow &window)
        {
            window.draw(*this);
        }

        std::shared_ptr<Common::Entity> m_entity;
    };
}

#endif