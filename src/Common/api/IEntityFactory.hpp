#ifndef IENTITY_FACTORY_HPP
#define IENTITY_FACTORY_HPP

#include "Entity.hpp"
#include <memory>

namespace SmartEvolution::Common
{
    class IEntityFactory
    {
    public:
        IEntityFactory() = default;
        virtual ~IEntityFactory() = default;

        virtual std::shared_ptr<Entity> getEntity(const GenomeSequence &) = 0;
    };
}

#endif