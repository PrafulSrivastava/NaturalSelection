#ifndef IACTION_FACTORY_HPP
#define IACTION_FACTORY_HPP

#include "IAction.hpp"
#include <functional>

namespace NaturalSelection::Action
{
    template <typename Entity, typename SFNAIE_Placeholder = std::void_t<>>
    class IActionFactory
    {
    };

    template <typename Entity>
    class IActionFactory<Entity,
                         std::enable_if_t<std::is_base_of<sf::Shape, Entity>::value>>
    {
        std::reference_wrapper<Entity> m_org;

    public:
        IActionFactory(Entity &org) : m_org(org) {}

        template <NaturalSelection::Common::Operation Op, typename... Args>
        decltype(auto) execute(Args... args)
        {
            return std::get<static_cast<int>(Op)>(task)(m_org, args...);
        }

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