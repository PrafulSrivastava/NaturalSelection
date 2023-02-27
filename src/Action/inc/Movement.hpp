#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "Common.hpp"
#include "Organism.hpp"
#include <random>

namespace SmartEvolution::Action
{
    constexpr auto step = 1;

    auto MOVE_NORTH = [](Entity::Organism &org)
    {
        Log(Log::INFO, "MOVE_NORTH");
        org.setPosition(org.getPosition().x, org.getPosition().y + step);
    };

    auto MOVE_EAST = [](Entity::Organism &org)
    {
        Log(Log::INFO, "MOVE_EAST");
        org.setPosition(org.getPosition().x + step, org.getPosition().y);
    };

    auto Move_West = [](Entity::Organism &org)
    {
        Log(Log::INFO, "Move_West");
        org.setPosition(org.getPosition().x - step, org.getPosition().y);
    };

    auto Move_South = [](Entity::Organism &org)
    {
        Log(Log::INFO, "Move_South");
        org.setPosition(org.getPosition().x, org.getPosition().y - step);
    };

    auto Move_Random = [](Entity::Organism &org)
    {
        Log(Log::INFO, "Move_Random");
        int8_t step_x = (rand() % 5) - 2;
        int8_t step_y = (rand() % 5) - 2;
        org.setPosition(org.getPosition().x + step_x, org.getPosition().y + step_y);
    };
};

#endif