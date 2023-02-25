#ifndef COMMON_TYPES_HPP
#define COMMON_TYPES_HPP

#include <iostream>

namespace SmartEvolution::Common
{
    // Brain
    using GenomeSequence = std::string;
    enum class NeuronType : uint8_t
    {
        Invalid = 0,
        MvN,
        MvS,
        MvE,
        MvW,
        MvR,
    };

    // Entity
    using FResolution = float;
    using NFResolution = int16_t;
    constexpr auto OrganismSize = 5;

    // Entity Factory

    // SFML
    constexpr auto Width = 800;
    constexpr auto Height = 600;
    constexpr auto Framerate = 120;
}

#endif