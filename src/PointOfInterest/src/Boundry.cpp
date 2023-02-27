#include "Boundry.hpp"

namespace SmartEvolution::PointOfInterest
{
    Boundry::Boundry()
    {
        m_boundryBlocks.resize(Common::Width, std::vector<BoundryBlock>(Common::Height));
    }

    void Boundry::init(std::shared_ptr<Common::Entity> entity)
    {
        for (auto x = 0; x < Common::Width; x++)
        {
            for (auto y = 0; y < Common::Height; y++)
            {
                m_boundryBlocks[x][y].setEntity(entity);
            }
        }

        m_isInitialized = true;
    }

    void Boundry::spawn(std::shared_ptr<Common::Entity> entity, std::reference_wrapper<sf::RenderWindow> window)
    {
        if (!m_isInitialized)
        {
            init(entity);
        }

        for (auto x = 0; x < Common::Width; x++)
        {
            for (auto y = 0; y < Common::Height; y++)
            {
                if (x == 0 || x == Common::Width - 1 || y == 0 || y == Common::Height - 1)
                {
                    m_boundryBlocks[x][y].setPosition(sf::Vector2f(x, y));
                    m_boundryBlocks[x][y].draw(window);
                }
            }
        }
    }
}