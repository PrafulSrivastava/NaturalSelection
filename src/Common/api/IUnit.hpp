#ifndef IUNIT_HPP
#define IUNIT_HPP

#include "CommonTypes.hpp"
#include "Utility.hpp"

namespace SmartEvolution::Common
{
    class IUnit : public sf::CircleShape
    {
    public:
        IUnit() = default;
        virtual ~IUnit() = default;
        virtual void run() = 0;
        virtual void update() = 0;
        virtual void draw(sf::RenderWindow &window) = 0;
    };

    template <typename T>
    class IUnitProcessor
    {
    private:
        T m_unit;

    public:
        void run()
        {
            m_unit.run();
        }
        void update()
        {
            m_unit.update();
        }
        void draw(sf::RenderWindow &window)
        {
            m_unit.draw(window);
        }
    };
}

#endif