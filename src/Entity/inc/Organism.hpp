#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include "Common.hpp"

namespace SmartEvolution::Entity
{
    class Organism : public sf::CircleShape
    {
    public:
        Organism() = default;
        ~Organism() = default;
    };
}

#endif