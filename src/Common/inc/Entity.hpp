#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "CommonTypes.hpp"
#include "Utility.hpp"

namespace SmartEvolution::Common
{
    struct Entity
    {
        Entity(const sf::Color &color, const FResolution &size)
            : m_color{color},
              m_size{size}
        {
            std::cout << __func__ << " with Color : " << m_color.toInteger() << std::endl;
        }
        virtual ~Entity() = default;
        virtual GenomeSequenceId getGenomeSequence() = 0;

        Entity(const Entity &) = delete;
        Entity &operator=(const Entity &) = delete;
        Entity(Entity &&) = default;
        Entity &operator=(Entity &&) = delete;

        sf::Color m_color;
        FResolution m_size;
    };

    struct LivingEntity : public Entity
    {
        LivingEntity(const sf::Color &color, const FResolution &size, const GenomeSequenceId &sequence)
            : Entity(color, size),
              m_sequence{sequence}
        {
            std::cout << "Adding Life to entity with GenomeSequenceId : " << m_sequence << std::endl;
        }

        GenomeSequenceId getGenomeSequence() override
        {
            return m_sequence;
        }

        GenomeSequenceId m_sequence{};
    };

    struct NonLivingEntity : public Entity
    {
        NonLivingEntity(const sf::Color &color, const FResolution &size)
            : Entity(color, size) {}

        GenomeSequenceId getGenomeSequence() override
        {
            return {};
        }
    };
}

#endif