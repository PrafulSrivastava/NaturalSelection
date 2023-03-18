#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "IEntity.hpp"
#include "CommonTypes.hpp"
#include "BrainProxy.hpp"

namespace NaturalSelection::Entity
{

    class Entity : public IEntity
    {
    public:
        Entity() = default;
        ~Entity() override = default;
        void Spawn() override;
        void Update() override;
        void Draw(std::reference_wrapper<sf::RenderWindow>) override;
        void ToString();

    private:
        Common::GenomeSequence m_sequence{};
        sf::CircleShape m_drawableEntity;
        Brain::BrainProxy m_brainProxy;
    };

}

#endif