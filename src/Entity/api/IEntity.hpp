#ifndef IENTITY_HPP
#define IENTITY_HPP

#include "Utility.hpp"
#include "CommonTypes.hpp"

namespace NaturalSelection::Entity
{

    class IEntity
    {
    public:
        virtual ~IEntity() = default;
        virtual void Spawn() = 0;
        virtual void Update() = 0;
        virtual bool Intersects(const sf::FloatRect &) = 0;
        virtual void Draw(std::reference_wrapper<sf::RenderWindow>) = 0;
    };

}

#endif