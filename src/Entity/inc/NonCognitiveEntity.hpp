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
        NonCognitiveEntity(const Common::NonCognitiveEntityType &type, bool isUntouchable = false)
            : m_type(type),
              m_isUntouchable(isUntouchable)

        {
        }

        NonCognitiveEntity(const Common::NonCognitiveEntityType &type, sf::Vector2f pos, bool isUntouchable = false)
            : m_type(type),
              m_isUntouchable(isUntouchable),
              m_position(pos)
        {
        }

        void Spawn()
        {
            m_drawableEntity = GetEntity(m_type);
            if (m_position.x != -Common::WIDTH && m_position.y != -Common::HEIGHT)
                m_drawableEntity.setPosition(m_position);

            if (m_isUntouchable)
            {
                m_drawableEntity.setFillColor(sf::Color::Red);
            }
        }

        void Update()
        {
        }

        Shape &GetDrawableEntity()
        {
            return m_drawableEntity;
        }

        bool Intersects(const sf::FloatRect &rhs)
        {
            auto lhs = m_drawableEntity.getGlobalBounds();
            return lhs.intersects(rhs);
        }

        void Draw(std::reference_wrapper<sf::RenderWindow> window)
        {
            window.get().draw(m_drawableEntity);
        }

        bool IsUntouchable()
        {
            return m_isUntouchable;
        }

        void ToString()
        {
        }

    private:
        Shape m_drawableEntity;
        Common::NonCognitiveEntityType m_type{Common::NonCognitiveEntityType::Invalid};
        bool m_isUntouchable{false};
        sf::Vector2f m_position{-Common::WIDTH, -Common::HEIGHT};
    };
}

#endif