#ifndef IACTION_HPP
#define IACTION_HPP

#include "Color.hpp"
#include "Movement.hpp"
#include <tuple>

namespace NaturalSelection::Action
{
    using Task = std::tuple<decltype(MvNorth) *, decltype(MvEast) *, decltype(MvWest) *, decltype(MvSouth) *, decltype(MvRandom) *, decltype(ChRed) *, decltype(ChGreen) *>;

    static Task task = std::make_tuple(&MvNorth, &MvEast, &MvWest, &MvSouth, &MvRandom, &ChRed, &ChGreen);

}

#endif