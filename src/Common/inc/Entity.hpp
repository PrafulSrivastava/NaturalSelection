#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "CommonTypes.hpp"
#include "Utility.hpp"

namespace SmartEvolution::Common
{
    struct Entity : sf::CircleShape
    {
        Entity(const sf::Color &color, const FResolution &size, const GenomeSequence &sequence)
            : m_color{color},
              m_size{size},
              m_sequence{sequence}
        {
            std::cout << __func__ << std::endl;
        }
        ~Entity() = default;

        Entity(const Entity &) = delete;
        Entity &operator=(const Entity &) = delete;
        Entity(Entity &&) = default;
        Entity &operator=(Entity &&) = delete;

        sf::Color m_color;
        FResolution m_size;
        GenomeSequence m_sequence{};
    };
}

#endif