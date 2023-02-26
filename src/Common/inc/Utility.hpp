#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "CommonTypes.hpp"

namespace SmartEvolution::Common
{
    class Utility
    {
        static std::unordered_map<std::string, bool> m_colorsUsed;
        static std::random_device m_device;
        static std::mt19937 m_randGenerator;

    public:
        template <typename T>
        static T getRandomNumberInRange(const T &min, const T &max);
        static sf::Color getFreshColor(const sf::Color &baseColor = sf::Color(0, 0, 0, 0));
        static std::string translateReaction(const ReactionType &);
    };

    template <typename T>
    T Utility::getRandomNumberInRange(const T &min, const T &max)
    {
        std::uniform_int_distribution<int> distribution(min, max);
        auto res = distribution(m_randGenerator);
        // std::cout << "Random: " << res << " in range : "
        //           << " {" << min << " ," << max << " }" << std::endl;
        return res;
    }
}

#endif