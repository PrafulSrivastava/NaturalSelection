#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "CommonTypes.hpp"
#include "CognitiveEntity.hpp"
#include "NonCognitiveEntity.hpp"
#include "BrainProxy.hpp"
#include "QuadTree.hpp"
#include "GenePool.hpp"

namespace NaturalSelection::Manager
{
    using OrgRef = std::reference_wrapper<Entity::CognitiveEntity<sf::CircleShape>>;

    class Manager
    {
    public:
        Manager();
        ~Manager() = default;

        void Init();
        void RunMainLoop();

    private:
        void InitNonCognitiveEntities();
        void InitCognitiveEntities();
        void GenerateTree();
        void ManageCollisions();
        void DrawOrganisms();

        sf::RenderWindow m_window;
        std::vector<Entity::NonCognitiveEntity<sf::RectangleShape>> m_nonCognitiveOrgs;
        Brain::BrainProxy m_proxy;
        std::list<Entity::CognitiveEntity<sf::CircleShape>> m_cognitiveOrgs;
        sf::Event m_event;
        Node<OrgRef> m_rootNode;
        Brain::GenePool m_genePool;
    };

}

#endif