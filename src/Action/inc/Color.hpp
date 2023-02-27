#ifndef COLOR_HPP
#define COLOR_HPP

#include "Common.hpp"
#include "Organism.hpp"

namespace SmartEvolution::Action
{
    auto Change_Color_Green = [](Entity::Organism &org)
    {
        Log(Log::INFO, "Change_Color_Green");
        org.setFillColor(sf::Color::Green);
    };

    auto Change_Color_Red = [](Entity::Organism &org)
    {
        Log(Log::INFO, "Change_Color_Red");
        org.setFillColor(sf::Color::Red);
    };
};

#endif