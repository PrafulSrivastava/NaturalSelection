#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "IEntity.hpp"
#include "BrainProxy.hpp"

namespace NaturalSelection::Entity
{

    template <typename Shape, typename SFNAIE_Placeholder = std::void_t<>>
    class Entity
    {
    };

    template <typename Shape>
    class Entity<Shape,
                 std::enable_if_t<std::is_base_of<sf::Shape, Shape>::value>> : public IEntity
    {
    public:
        Entity(Brain::BrainProxy &proxy) : m_brainProxy(proxy)
        {
            m_sequence.resize(Common::GenomeSequenceLength);
            for (size_t i = 0; i < Common::GenomeSequenceLength; i++)
            {
                m_sequence[i] = ((rand() % 2) == 0) ? '0' : '1';
            }
        }

        Entity(Brain::BrainProxy &proxy, const Common::GenomeSequence &sequence)
            : m_sequence(sequence),
              m_brainProxy(proxy)
        {
        }

        void Spawn()
        {
            if constexpr (std::is_same<Shape, sf::RectangleShape>::value)
            {
                m_drawableEntity.setPosition(rand() % Common::WIDTH, rand() % Common::HEIGHT);
                m_drawableEntity.setFillColor(sf::Color::Green);
                m_drawableEntity.setSize(sf::Vector2f(100, 0));
                m_drawableEntity.setOutlineThickness(1);
                m_drawableEntity.setOutlineColor(sf::Color::Red);
            }

            if constexpr (std::is_same<Shape, sf::CircleShape>::value)
            {
                m_drawableEntity.setPosition(rand() % Common::WIDTH, rand() % Common::HEIGHT);
                m_drawableEntity.setFillColor(sf::Color::Green);
                m_drawableEntity.setRadius(5);
                m_drawableEntity.setPointCount(3);
                m_drawableEntity.setOutlineThickness(1);
                m_drawableEntity.setOutlineColor(sf::Color::Red);
            }
        }

        void Update()
        {
            m_brainProxy.get().React(m_sequence, Common::StimuliType::Mechanical, std::ref(m_drawableEntity));
        }

        void Draw(std::reference_wrapper<sf::RenderWindow> window)
        {
            window.get().draw(m_drawableEntity);
        }

        void ToString()
        {
            Log(Log::INFO, "{X, Y} :", "{", m_drawableEntity.getPosition().x, ",", m_drawableEntity.getPosition().y, "}");
        }

    private:
        Common::GenomeSequence m_sequence{};
        Shape m_drawableEntity;
        std::reference_wrapper<Brain::BrainProxy> m_brainProxy;
    };
}

#endif