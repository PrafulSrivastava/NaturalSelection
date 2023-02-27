#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <iostream>
#include <memory>
#include <unordered_map>
#include <array>
#include <random>
#include <vector>
#include <bitset>
#include <SFML/Graphics.hpp>

namespace SmartEvolution::Common
{
    // Brain
    constexpr auto GenomeSequenceLength = 5;
    using GenomeSequence = std::bitset<GenomeSequenceLength>;
    using GenomeSequenceId = std::string;
    /*
        1 0 0 1 1
        N S E W R
        An organism with this sequence moves North, West or Random
    */
    enum class ReactionType : uint8_t
    {
        Invalid = 0,
        MvN = 1,
        MvS = 2,
        MvE = 3,
        MvW = 4,
        MvR = 5,
    };

    enum class StimuliType : uint8_t
    {
        Invalid = 0,
        Mechanical,
        Thermal,
        Chemical
    };

    // Entity
    using FResolution = float;
    using NFResolution = int16_t;
    constexpr auto OrganismSize = 5;

    enum class EntityType : uint8_t
    {
        Invalid = 0,
        Living,
        Boundry
    };

    // SFML
    constexpr auto Width = 800;
    constexpr auto Height = 600;
    constexpr auto Framerate = 120;
    constexpr auto WindowName = "NaturalSelection";

    // POI
    constexpr auto BoundrySize = 5;
    using BoundrySet = std::array<sf::Vector2f, (Width + Height) * 2>;
}

#endif