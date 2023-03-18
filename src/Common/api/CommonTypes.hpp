#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <array>
#include <functional>
#include <unordered_map>
#include <SFML/Graphics.hpp>

namespace NaturalSelection::Common
{
    enum class NeuronType : int8_t
    {
        Invalid = -1,
        MvN,
        MvS,
        MvE,
        MvW,
        MvR,
    };

    using GenomeSequence = std::string;
    constexpr auto GenomeSequenceLength = 5;

    enum class StimuliType : int8_t
    {
        Invalid = -1,
        Mechanical,
        Chemical
    };

    constexpr auto HEIGHT = 800;
    constexpr auto WIDTH = 800;
}

#endif