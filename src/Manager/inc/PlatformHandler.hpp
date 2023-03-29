#ifndef PLATFORM_HANDLER_HPP
#define PLATFORM_HANDLER_HPP

#include "IPlatform.hpp"
#include "CommonTypes.hpp"

namespace NaturalSelection::Manager
{
    template <typename Platform, typename SFINAE_PlaceHolder = std::void_t<>>
    class PlatformHandler
    {
    };

    template <typename Platform>
    class PlatformHandler<Platform, std::enable_if_t<std::is_base_of<IPlatform, Platform>::value>>
    {
    public:
        PlatformHandler() : m_platform(std::make_shared<Platform>())
        {
        }
        ~PlatformHandler()
        {
            m_platform.reset();
        }
        void Init(const int32_t &width, const int32_t &height)
        {
            m_platform->Init(width, height);
        }
        void Register(std::reference_wrapper<Entity::CognitiveEntity<sf::CircleShape>> org)
        {
            m_platform->Register(org);
        }
        void Update(const EntityId &id)
        {
            m_platform->Update(id);
        }
        std::vector<EntityId> Fetch(const EntityId &id)
        {
            return m_platform->Fetch(id);
        }
        void Reset()
        {
            m_platform->Reset();
        }
        void Draw(std::reference_wrapper<sf::RenderWindow> window)
        {
            m_platform->Draw(window);
        }

    private:
        std::shared_ptr<Platform> m_platform;
    };
}

#endif
