#ifndef ENTITY_FACTORY_HPP
#define ENTITY_FACTORY_HPP

#include "IEntityFactory.hpp"

namespace SmartEvolution::Common
{
    class EntityFactory : public IEntityFactory
    {
    private:
        std::unordered_map<GenomeSequenceId, std::shared_ptr<Entity>> m_entites;

    public:
        EntityFactory() = default;
        ~EntityFactory() override = default;

        EntityFactory(const EntityFactory &) = delete;
        EntityFactory &operator=(const EntityFactory &) = delete;
        EntityFactory(EntityFactory &&) = delete;
        EntityFactory &operator=(EntityFactory &&) = delete;

        std::shared_ptr<Entity> getEntity(const EntityType &, const GenomeSequence &) override;
        std::shared_ptr<Entity> getEntity(const EntityType &) override;
    };
}

#endif