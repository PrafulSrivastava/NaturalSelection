#ifndef NON_COGNITIVE_ENTITY_HPP
#define NON_COGNITIVE_ENTITY_HPP

#include "IEntity.hpp"
#include "BrainProxy.hpp"
#include "EntityMap.hpp"

namespace NaturalSelection::Entity
{

    template <typename Shape, typename SFNAIE_Placeholder = std::void_t<>>
    class NonCognitiveEntity
    {
    };

    template <typename Shape>
    class NonCognitiveEntity<Shape,
                             std::enable_if_t<std::is_base_of<sf::Shape, Shape>::value>> : public IEntity
    {
    public:
        NonCognitiveEntity(const Common::NonCognitiveEntityType &type)
            : m_type(type)
        {
        }

        void Spawn()
        {
            m_drawableEntity = GetEntity(m_type);
        }

        void Update()
        {
        }

        bool Intersects(const sf::FloatRect &rhs)
        {
            auto lhs = m_drawableEntity.getGlobalBounds();
            return lhs.intersects(rhs);
        }

        sf::Vector2f GetPosition()
        {
            return m_drawableEntity.getPosition();
        }

        sf::FloatRect GetGlobalBounds()
        {
            return m_drawableEntity.getGlobalBounds();
        }

        void Draw(std::reference_wrapper<sf::RenderWindow> window)
        {
            window.get().draw(m_drawableEntity);
        }

        void ToString()
        {
        }

    private:
        Shape m_drawableEntity;
        Common::NonCognitiveEntityType m_type{Common::NonCognitiveEntityType::Invalid};
    };
}

#endif