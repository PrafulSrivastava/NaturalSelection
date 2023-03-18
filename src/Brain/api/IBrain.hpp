#ifndef IBRAIN_HPP
#define IBRAIN_HPP

#include "CommonTypes.hpp"

namespace NaturalSelection::Brain
{

    class IBrain
    {
    public:
        virtual ~IBrain() = default;
        virtual void React(const Common::StimuliType &, std::reference_wrapper<sf::CircleShape>) = 0;
    };

}

#endif