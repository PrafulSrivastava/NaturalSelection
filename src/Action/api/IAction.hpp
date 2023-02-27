#ifndef IACTION_HPP
#define IACTION_HPP

#include "Color.hpp"
#include "Movement.hpp"
#include <tuple>

namespace SmartEvolution::Action
{
    using Action = std::tuple<decltype(Move_North) *, decltype(Move_East) *, decltype(Move_West) *, decltype(Move_South) *, decltype(Move_Random) *, decltype(Change_Color_Green) *, decltype(Change_Color_Red) *>;

    Action func = std::make_tuple(&Move_North, &Move_East, &Move_West, &Move_South, &Move_Random, &Change_Color_Green, &Change_Color_Red);
}

#endif