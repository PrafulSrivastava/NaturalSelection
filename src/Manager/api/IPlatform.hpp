#ifndef IPLATFORM_HPP
#define IPLATFORM_HPP

#include "CognitiveEntity.hpp"

namespace NaturalSelection::Manager
{
    using EntityId = int32_t;
    using TargetId = int32_t;
    using BlockId = int32_t;
    using Position = sf::Vector2f;

    class IPlatform
    {
    public:
        virtual ~IPlatform() = default;

        virtual void Init(const int32_t &, const int32_t &) = 0;
        virtual void Register(std::reference_wrapper<Entity::CognitiveEntity<sf::CircleShape>>) = 0;
        virtual void Update(const EntityId &id) = 0;
        virtual std::vector<EntityId> Fetch(const EntityId &id) = 0;
        virtual void Reset() = 0;
        virtual void Draw(std::reference_wrapper<sf::RenderWindow>) = 0;
    };
}

#endif
