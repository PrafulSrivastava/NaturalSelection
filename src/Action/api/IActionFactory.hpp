#ifndef IACTION_FACTORY_HPP
#define IACTION_FACTORY_HPP

#include "IAction.hpp"
#include <functional>

namespace SmartEvolution::Action
{
    template <typename Entity>
    class IActionFactory
    {
        std::reference_wrapper<Entity> m_org;

    public:
        IActionFactory(Entity &org) : m_org(org) {}

        template <typename Task, typename... Args, std::enable_if_t<std::is_void<decltype(std::declval<Task>()(std::declval<decltype(m_org)>(), std::declval<Args>()...))>::value>>
        decltype(std::declval<Task>()(std::declval<decltype(m_org)>(), std::declval<Args>()...))
        execute(Task task, Args... args)
        {
            task(m_org, args...);
        }

        template <typename Task, typename... Args>
        decltype(std::declval<Task>()(std::declval<decltype(m_org)>(), std::declval<Args>()...))
        execute(Task task, Args... args)
        {
            return task(m_org, args...);
        }

        template <typename Task, typename... Args, std::enable_if_t<std::is_void<decltype(std::declval<Task>()(std::declval<Args>()...))>::value>>
        decltype(std::declval<Task>()(std::declval<Args>()...))
        execute(Task task, Args... args)
        {
            task(args...);
        }

        template <typename Task, typename... Args>
        decltype(std::declval<Task>()(std::declval<Args>()...))
        execute(Task task, Args... args)
        {
            return task(args...);
        }
    };
}

#endif