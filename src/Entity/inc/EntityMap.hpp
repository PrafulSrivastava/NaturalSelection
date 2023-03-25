#ifndef ENTITY_MAP_HPP
#define ENTITY_MAP_HPP

#include "CommonTypes.hpp"
#include "Utility.hpp"

namespace NaturalSelection::Entity
{
    static sf::RectangleShape GetEntity(const Common::NonCognitiveEntityType &type)
    {
        sf::RectangleShape entity;
        switch (type)
        {
        case Common::NonCognitiveEntityType::NorthBoundry:
            entity.setFillColor(sf::Color::Blue);
            entity.setSize(sf::Vector2f(Common::WIDTH, Common::BoundryWidth));
            entity.setPosition(Common::WIDTH / 2, Common::BoundryWidth / 2);
            break;
        case Common::NonCognitiveEntityType::SouthBoundry:
            entity.setFillColor(sf::Color::Blue);
            entity.setSize(sf::Vector2f(Common::WIDTH, Common::BoundryWidth));
            entity.setPosition(Common::WIDTH / 2, Common::HEIGHT - Common::BoundryWidth / 2);
            break;
        case Common::NonCognitiveEntityType::EastBoundry:
            entity.setFillColor(sf::Color::Blue);
            entity.setSize(sf::Vector2f(Common::BoundryWidth, Common::HEIGHT));
            entity.setPosition(Common::BoundryWidth / 2, Common::HEIGHT / 2);
            break;
        case Common::NonCognitiveEntityType::WestBoundry:
            entity.setFillColor(sf::Color::Blue);
            entity.setSize(sf::Vector2f(Common::BoundryWidth, Common::HEIGHT));
            entity.setPosition(Common::WIDTH - Common::BoundryWidth / 2, Common::HEIGHT / 2);
            break;
        }
        Common::Utility::SetOriginToCenter(entity);

        return entity;
    }
}

#endif