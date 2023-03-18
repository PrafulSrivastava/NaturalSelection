#include "Entity.hpp"

namespace NaturalSelection::Entity
{

    void Entity::Spawn()
    {
        m_sequence.resize(Common::GenomeSequenceLength);
        for (size_t i = 0; i < Common::GenomeSequenceLength; i++)
        {
            m_sequence[i] = ((rand() % 2) == 0) ? '0' : '1';
        }

        std::cout << __func__ << " GenomeSequence : " << m_sequence << std::endl;

        m_drawableEntity.setPosition(rand() % Common::WIDTH, rand() % Common::HEIGHT);
        m_drawableEntity.setFillColor(sf::Color::Green);
        m_drawableEntity.setRadius(5);
    }

    void Entity::Update()
    {
        m_brainProxy.React(m_sequence, Common::StimuliType::Mechanical, std::ref(m_drawableEntity));
    }

    void Entity::Draw(std::reference_wrapper<sf::RenderWindow> window)
    {
        window.get().draw(m_drawableEntity);
    }

    void Entity::ToString()
    {
        std::cout << " Position of Entity : {" << m_drawableEntity.getPosition().x << ", " << m_drawableEntity.getPosition().y << "}" << std::endl;
    }

};