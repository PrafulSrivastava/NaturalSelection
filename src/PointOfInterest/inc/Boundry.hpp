#ifndef BOUNDRY_HPP
#define BOUNDRY_HPP

#include "CommonTypes.hpp"
#include "IPointOfInterestProxy.hpp"
#include "IUnit.hpp"
#include <vector>

namespace SmartEvolution::PointOfInterest
{
    struct BoundryBlock : public Common::IUnit
    {
        BoundryBlock()
        {
            setPointCount(4);
        }

        ~BoundryBlock() override = default;

        void setEntity(std::shared_ptr<Common::Entity> entity)
        {
            m_entity = entity;
            setFillColor(m_entity->m_color);
            setRadius(m_entity->m_size);
            Common::Utility::setOriginToCenter(*this);
        }

        void run() override
        {
        }

        void update() override
        {
        }

        void draw(sf::RenderWindow &window) override
        {
            window.draw(*this);
        }
        std::shared_ptr<Common::Entity> m_entity{nullptr};
    };

    class Boundry : public IPointOfInterest
    {
    public:
        Boundry();
        ~Boundry() override = default;
        Boundry(const Boundry &) = delete;
        Boundry &operator=(const Boundry &) = delete;
        Boundry(Boundry &&) = delete;
        Boundry &operator=(Boundry &&) = delete;

        void spawn(std::shared_ptr<Common::Entity>, std::reference_wrapper<sf::RenderWindow>) override;

    private:
        std::vector<std::vector<BoundryBlock>> m_boundryBlocks;
        // std::array<std::array<BoundryBlock, Common::Width>, Common::Height> m_boundryBlocks;
        bool m_isInitialized{false};

        void init(std::shared_ptr<Common::Entity>);
    };
}

#endif