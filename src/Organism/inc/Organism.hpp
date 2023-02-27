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
        }

        ~Organism() = default;

        void run() override
        {
        }
        void update() override
        {
        }
        void draw(sf::RenderWindow &window) override
        {
            window.draw(*this);
        }

        std::shared_ptr<Common::Entity> m_entity{nullptr};
    };
}

#endif