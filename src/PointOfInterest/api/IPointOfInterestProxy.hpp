#ifndef IPOINT_OF_INTEREST_PROXY_HPP
#define IPOINT_OF_INTEREST_PROXY_HPP

#include "CommonTypes.hpp"
#include "Entity.hpp"

namespace SmartEvolution::PointOfInterest
{
    class IPointOfInterest
    {
    public:
        IPointOfInterest() = default;
        virtual ~IPointOfInterest() = default;

        virtual void spawn(std::shared_ptr<Common::Entity>, std::reference_wrapper<sf::RenderWindow>) = 0;
    };

    template <typename T>
    class IPointOfInterestProxy
    {
    public:
        IPointOfInterestProxy() = default;
        void spawn(std::shared_ptr<Common::Entity> entity, std::reference_wrapper<sf::RenderWindow> window)
        {
            m_poi.spawn(entity, window);
        }

    private:
        T m_poi;
    };

}

#endif