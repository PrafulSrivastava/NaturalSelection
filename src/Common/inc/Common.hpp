#ifndef COMMON_HPP
#define COMMON_HPP

#include "ConfigParser.hpp"
#include <SFML/Graphics.hpp>

#define Log(args, ...) SmartEvolution::Common::Logger::Logging(args, __VA_ARGS__)
using Log = SmartEvolution::Common::LogLevel;

namespace SmartEvolution
{
    enum class Operation
    {
        // Command Operation
        Move_North = 0,
        Move_East,
        Move_West,
        Move_South,
        Move_Random,
        Change_Color_Green,
        Change_Color_Red,
    };
}

#endif