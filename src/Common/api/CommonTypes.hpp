#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <array>
#include <functional>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "ConfigParser.hpp"

#define Log(args, ...) NaturalSelection::Trace::Logger::Logging(args, __VA_ARGS__)
using Log = NaturalSelection::Trace::LogLevel;

namespace NaturalSelection::Common
{
    enum class Operation : int8_t
    {
        Invalid = -1,

        // Movement
        MvNorth,
        MvEast,
        MvWest,
        MvSouth,
        MvRandom,

        // Color
        ChRed,
        ChGreen,
    };

    using GenomeSequence = std::string;
    constexpr auto GenomeSequenceLength = 5;

    enum class StimuliType : int8_t
    {
        Invalid = -1,
        Mechanical,
        Chemical
    };

    constexpr auto HEIGHT = 5000;
    constexpr auto WIDTH = 5000;
    constexpr auto WINDOW_NAME = "NaturalEvolution";

    using Actions = std::vector<Operation>;
}

#endif