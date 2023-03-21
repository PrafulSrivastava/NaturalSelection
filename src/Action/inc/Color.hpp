#ifndef COLOR_HPP
#define COLOR_HPP

#include "CommonTypes.hpp"

namespace NaturalSelection::Action
{
    static void ChGreen(sf::Shape &org)
    {
        Log(Log::DEBUG, __func__);
        org.setFillColor(sf::Color::Green);
    };

    static void ChRed(sf::Shape &org)
    {
        Log(Log::DEBUG, __func__);
        org.setFillColor(sf::Color::Red);
    };
};

#endif