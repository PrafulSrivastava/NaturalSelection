#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "CommonTypes.hpp"
#include <random>

namespace NaturalSelection::Action
{
    constexpr auto step = 20;

    static void MvNorth(sf::Transformable &org)
    {
        Log(Log::DEBUG, __func__);
        org.move(0, -step);
    };

    static void MvEast(sf::Transformable &org)
    {
        Log(Log::DEBUG, __func__);
        org.move(step, 0);
    };

    static void MvWest(sf::Transformable &org)
    {
        Log(Log::DEBUG, __func__);
        org.move(-step, 0);
    };

    static void MvSouth(sf::Transformable &org)
    {
        Log(Log::DEBUG, __func__);
        org.move(0, step);
    };

    static void MvRandom(sf::Transformable &org)
    {
        Log(Log::DEBUG, __func__);
        int8_t step_x = (rand() % 2) * std::pow(-1, (rand() % 2) + 1);
        int8_t step_y = (rand() % 2) * std::pow(-1, (rand() % 2) + 1);
        org.move(step * step_x, step * step_y);
    };
};

#endif