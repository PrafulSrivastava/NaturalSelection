#include "Utility.hpp"

namespace NaturalSelection::Common
{
    std::unordered_map<std::string, bool> Utility::m_colorsUsed;
    std::random_device Utility::m_device;
    std::mt19937 Utility::m_randGenerator(m_device());

    void Utility::SetOriginToCenter(sf::Shape &entity)
    {
        auto rect = entity.getGlobalBounds();
        entity.setOrigin(rect.width / 2, rect.height / 2);
    }
}