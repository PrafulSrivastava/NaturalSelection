#ifndef COGNITIVE_ENTITY_HPP
#define COGNITIVE_ENTITY_HPP

#include "IEntity.hpp"
#include "BrainProxy.hpp"

namespace NaturalSelection::Entity
{

    template <typename Shape, typename SFNAIE_Placeholder = std::void_t<>>
    class CognitiveEntity
    {
    };

    template <typename Shape>
    class CognitiveEntity<Shape,
                          std::enable_if_t<std::is_base_of<sf::Shape, Shape>::value>> : public IEntity
    {
    public:
        CognitiveEntity(Brain::BrainProxy &proxy, int id) : m_brainProxy(proxy), m_id(id)
        {
            m_sequence.resize(Common::GenomeSequenceLength);
            for (size_t i = 0; i < Common::GenomeSequenceLength; i++)
            {
                m_sequence[i] = ((rand() % 2) == 0) ? '0' : '1';
            }
        }

        CognitiveEntity(Brain::BrainProxy &proxy, const Common::GenomeSequence &sequence, int id)
            : m_sequence(sequence),
              m_brainProxy(proxy),
              m_id(id)
        {
        }

        void Spawn()
        {
            if constexpr (std::is_same<Shape, sf::RectangleShape>::value)
            {
                m_drawableEntity.setPosition(rand() % (Common::WIDTH / 2) + Common::WIDTH / 4, rand() % (Common::HEIGHT / 2) + Common::HEIGHT / 4);
                m_drawableEntity.setFillColor(sf::Color::Green);
                m_drawableEntity.setSize(sf::Vector2f(100, 0));
                m_drawableEntity.setOutlineThickness(1);
                m_drawableEntity.setOutlineColor(sf::Color::Red);
            }

            if constexpr (std::is_same<Shape, sf::CircleShape>::value)
            {
                m_drawableEntity.setPosition(rand() % (Common::WIDTH / 2) + Common::WIDTH / 4, rand() % (Common::HEIGHT / 2) + Common::HEIGHT / 4);

                m_drawableEntity.setFillColor(sf::Color::Green);
                m_drawableEntity.setRadius(4);
                m_drawableEntity.setOutlineThickness(1);
                m_drawableEntity.setOutlineColor(sf::Color::Red);
            }
        }

        void Update()
        {
            sf::Shape &shape = m_drawableEntity;
            m_brainProxy.get().React(m_sequence, Common::StimuliType::Mechanical, std::ref(shape));
            Common::Utility::SetOriginToCenter(m_drawableEntity);
        }

        bool Intersects(const sf::FloatRect &rhs)
        {
            auto lhs = m_drawableEntity.getGlobalBounds();
            return lhs.intersects(rhs);
        }

        Shape &GetDrawableEntity()
        {
            return m_drawableEntity;
        }

        void Draw(std::reference_wrapper<sf::RenderWindow> window)
        {
            window.get().draw(m_drawableEntity);
        }

        int GetId()
        {
            return m_id;
        }

        std::string GetGenomeSequence()
        {
            return m_sequence;
        }

        void ToString()
        {
            Log(Log::INFO, "{X, Y} :", "{", m_drawableEntity.getPosition().x, ",", m_drawableEntity.getPosition().y, "}");
        }

    private:
        Common::GenomeSequence m_sequence{};
        Shape m_drawableEntity;
        std::reference_wrapper<Brain::BrainProxy> m_brainProxy;
        int m_id{-1};
    };
}

#endif