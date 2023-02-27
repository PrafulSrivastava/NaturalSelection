#ifndef TEST_HPP
#define TEST_HPP

#include "Common.hpp"
#include "Organism.hpp"

namespace SmartEvolution::Action
{
    constexpr auto offset = 1;

    auto MOVE_NORTH_VOID = [](Entity::Organism &org)
    {
        Log(Log::INFO, "MOVE_NORTH_VOID");
        org.setPosition(org.getPosition().x, org.getPosition().y + offset);
    };

    auto MOVE_NORTH_INT = [](Entity::Organism &org)
    {
        Log(Log::INFO, "MOVE_NORTH_INT");
        org.setPosition(org.getPosition().x, org.getPosition().y + offset);

        return offset;
    };
}

#endif