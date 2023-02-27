#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "Common.hpp"
#include "Organism.hpp"
#include <random>

namespace SmartEvolution::Action
{
    constexpr auto step = 1;

    void Move_North(Entity::Organism &org)
    {
        Log(Log::INFO, __func__);
        org.setPosition(org.getPosition().x, org.getPosition().y + step);
    }
    void Move_East(Entity::Organism &org)
    {
        Log(Log::INFO, __func__);
        org.setPosition(org.getPosition().x + step, org.getPosition().y);
    }
    void Move_West(Entity::Organism &org)
    {
        Log(Log::INFO, __func__);
        org.setPosition(org.getPosition().x - step, org.getPosition().y);
    }
    void Move_South(Entity::Organism &org)
    {
        Log(Log::INFO, __func__);
        org.setPosition(org.getPosition().x, org.getPosition().y - step);
    }
    void Move_Random(Entity::Organism &org)
    {
        Log(Log::INFO, __func__);
        int8_t step_x = (rand() % 5) - 2;
        int8_t step_y = (rand() % 5) - 2;
        org.setPosition(org.getPosition().x + step_x, org.getPosition().y + step_y);
    }
};

#endif