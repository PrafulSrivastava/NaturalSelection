#include "Utility.hpp"

namespace SmartEvolution::Common
{
    std::unordered_map<std::string, bool> Utility::m_colorsUsed;

    NFResolution Utility::getRandomNumberInRange(NFResolution min, NFResolution max)
    {
        return rand() % max + min;
    }

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

            auto baseToEdit = getRandomNumberInRange(0, 4);
            colorPallet[baseToEdit] = colorPallet[baseToEdit] + (getRandomNumberInRange(20, 100));
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
}