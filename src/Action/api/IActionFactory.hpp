#ifndef IACTION_FACTORY_HPP
#define IACTION_FACTORY_HPP

#include "IAction.hpp"
#include <functional>

namespace SmartEvolution::Action
{
    class IActionFactory
    {
        std::reference_wrapper<Entity::Organism> m_org;

    public:
        IActionFactory(Entity::Organism &org) : m_org(org) {}

        template <typename T, Operation Op, typename... Args>
        T execute(Args... args)
        {
            return std::get<static_cast<int>(Op)>(func)(m_org, args...);
        }

        template <Operation Op, typename... Args>
        void execute(Args... args)
        {
            std::get<static_cast<int>(Op)>(func)(m_org, args...);
        }
    };
}

#endif