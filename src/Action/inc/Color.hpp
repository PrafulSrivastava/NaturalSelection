#ifndef COLOR_HPP
#define COLOR_HPP

#include "Common.hpp"
#include "Organism.hpp"

namespace SmartEvolution::Action
{
    void Change_Color_Green(Entity::Organism &org)
    {
        Log(Log::INFO, __func__);
        org.setFillColor(sf::Color::Green);
    }
    void Change_Color_Red(Entity::Organism &org)
    {
        Log(Log::INFO, __func__);
        org.setFillColor(sf::Color::Red);
    }
};

#endif