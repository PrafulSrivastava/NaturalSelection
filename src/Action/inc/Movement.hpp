#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "CommonTypes.hpp"
#include <random>

namespace NaturalSelection::Action
{
    constexpr auto step = 1;

    static void MvNorth(sf::Transformable &org)
    {
        Log(Log::DEBUG, __func__);
        org.setPosition(org.getPosition().x, org.getPosition().y - step);
    };

    static void MvEast(sf::Transformable &org)
    {
        Log(Log::DEBUG, __func__);
        org.setPosition(org.getPosition().x + step, org.getPosition().y);
    };

    static void MvWest(sf::Transformable &org)
    {
        Log(Log::DEBUG, __func__);
        org.setPosition(org.getPosition().x - step, org.getPosition().y);
    };

    static void MvSouth(sf::Transformable &org)
    {
        Log(Log::DEBUG, __func__);
        org.setPosition(org.getPosition().x, org.getPosition().y + step);
    };

    static void MvRandom(sf::Transformable &org)
    {
        Log(Log::DEBUG, __func__);
        int8_t step_x = (rand() % 5) - 2;
        int8_t step_y = (rand() % 5) - 2;
        org.setPosition(org.getPosition().x + step_x, org.getPosition().y + step_y);
    };
};

#endif