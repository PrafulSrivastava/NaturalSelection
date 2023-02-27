#ifndef IENTITY_FACTORY_HPP
#define IENTITY_FACTORY_HPP

#include "Entity.hpp"

namespace SmartEvolution::Common
{
    class IEntityFactory
    {
    public:
        IEntityFactory() = default;
        virtual ~IEntityFactory() = default;

        virtual std::shared_ptr<Entity> getEntity(const EntityType &, const GenomeSequence &) = 0;
        virtual std::shared_ptr<Entity> getEntity(const EntityType &) = 0;
    };
}

#endif