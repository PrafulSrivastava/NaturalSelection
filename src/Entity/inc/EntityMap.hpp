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
            entity.setFillColor(sf::Color::White);
            entity.setSize(sf::Vector2f(Common::WIDTH, 20));
            entity.setPosition(Common::WIDTH / 2, 10);
            break;
        case Common::NonCognitiveEntityType::SouthBoundry:
            entity.setFillColor(sf::Color::White);
            entity.setSize(sf::Vector2f(Common::WIDTH, 20));
            entity.setPosition(Common::WIDTH / 2, Common::HEIGHT - 10);
            break;
        case Common::NonCognitiveEntityType::EastBoundry:
            entity.setFillColor(sf::Color::White);
            entity.setSize(sf::Vector2f(20, Common::HEIGHT));
            entity.setPosition(10, Common::HEIGHT / 2);
            break;
        case Common::NonCognitiveEntityType::WestBoundry:
            entity.setFillColor(sf::Color::White);
            entity.setSize(sf::Vector2f(20, Common::HEIGHT));
            entity.setPosition(Common::WIDTH - 10, Common::HEIGHT / 2);
            break;
        }
        Common::Utility::SetOriginToCenter(entity);

        return entity;
    }
}

#endif