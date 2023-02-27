#ifndef COMMON_HPP
#define COMMON_HPP

#include "ConfigParser.hpp"
#include <SFML/Graphics.hpp>

#define Log(args, ...) SmartEvolution::Common::Logger::Logging(args, __VA_ARGS__)
using Log = SmartEvolution::Common::LogLevel;

namespace SmartEvolution
{

}

#endif