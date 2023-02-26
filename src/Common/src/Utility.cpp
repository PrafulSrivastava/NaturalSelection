#include "Utility.hpp"

namespace SmartEvolution::Common
{
    std::unordered_map<std::string, bool> Utility::m_colorsUsed;
    std::random_device Utility::m_device;
    std::mt19937 Utility::m_randGenerator(m_device());

    sf::Color Utility::getFreshColor(const sf::Color &baseColor)
    {
        sf::Color newColor;

        while (true)
        {
            std::array<NFResolution, 4> colorPallet;
            colorPallet[0] = baseColor.a;
            colorPallet[1] = baseColor.b;
            colorPallet[2] = baseColor.g;
            colorPallet[3] = baseColor.r;

            auto baseToEdit = getRandomNumberInRange(0, 3);
            colorPallet[baseToEdit] = colorPallet[baseToEdit] + (getRandomNumberInRange(0, 100));
            std::string id{};
            for (const auto &i : colorPallet)
            {
                id += std::to_string(i);
            }

            if (!m_colorsUsed[id])
            {
                m_colorsUsed[id] = true;
                newColor = sf::Color(colorPallet[0], colorPallet[1], colorPallet[2], colorPallet[3]);
                break;
            }
        }
        return newColor;
    }

    std::string Utility::translateReaction(const ReactionType &reaction)
    {
        switch (reaction)
        {
        case ReactionType::Invalid:
            return "ReactionType::Invalid";
        case ReactionType::MvN:
            return "ReactionType::MvN";
        case ReactionType::MvS:
            return "ReactionType::MvS";
        case ReactionType::MvE:
            return "ReactionType::MvE";
        case ReactionType::MvW:
            return "ReactionType::MvW";
        case ReactionType::MvR:
            return "ReactionType::MvR";
        }
    }
}