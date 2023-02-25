#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <SFML/Graphics.hpp>
#include <random>
#include <unordered_map>
#include <array>
#include "CommonTypes.hpp"

namespace SmartEvolution::Common
{
    class Utility
    {
        static std::unordered_map<std::string, bool> m_colorsUsed;

    public:
        static NFResolution getRandomNumberInRange(NFResolution min, NFResolution max);
        static sf::Color getFreshColor(const sf::Color &baseColor = sf::Color(0, 0, 0, 0));
    };

}

#endif