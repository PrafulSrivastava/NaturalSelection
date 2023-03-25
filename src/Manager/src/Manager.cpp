#include "Manager.hpp"
#include "Benchmark.hpp"

namespace NaturalSelection::Manager
{

    Manager::Manager() : m_window{sf::VideoMode(Common::WIDTH, Common::HEIGHT), Common::WINDOW_NAME},
                         m_rootNode{sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)}
    {
    }

    void Manager::InitNonCognitiveEntities()
    {
        Benchmark<std::chrono::microseconds> bm(__func__);

        Entity::NonCognitiveEntity<sf::RectangleShape> nBoundry(Common::NonCognitiveEntityType::NorthBoundry, true);
        Entity::NonCognitiveEntity<sf::RectangleShape> sBoundry(Common::NonCognitiveEntityType::SouthBoundry);
        Entity::NonCognitiveEntity<sf::RectangleShape> eBoundry(Common::NonCognitiveEntityType::EastBoundry);
        Entity::NonCognitiveEntity<sf::RectangleShape> wBoundry(Common::NonCognitiveEntityType::WestBoundry);

        m_nonCognitiveOrgs.push_back(nBoundry);
        m_nonCognitiveOrgs.push_back(sBoundry);
        m_nonCognitiveOrgs.push_back(eBoundry);
        m_nonCognitiveOrgs.push_back(wBoundry);

        for (int i = 0; i < m_nonCognitiveOrgs.size(); i++)
        {
            m_nonCognitiveOrgs[i].Spawn();
        }
    }

    void Manager::InitCognitiveEntities()
    {
        Benchmark<std::chrono::microseconds> bm(__func__);
        for (auto i = 0; i < Common::CognitiveOrganismCount; i++)
        {
            auto org = Entity::CognitiveEntity<sf::CircleShape>(std::ref(m_proxy), m_genePool.GetGenomeSequence(), i);
            org.Spawn();
            m_cognitiveOrgs.emplace_back(std::move(org));
        }
    }

    void Manager::Init()
    {
        InitNonCognitiveEntities();
        InitCognitiveEntities();
    }

    void Manager::GenerateTree()
    {
        Benchmark<std::chrono::microseconds> bm(__func__);

        m_rootNode.Flush();

        for (auto itr = m_cognitiveOrgs.begin(); itr != m_cognitiveOrgs.end(); itr++)
        {
            QuadTree<OrgRef>::Insert(m_rootNode, itr->GetDrawableEntity().getPosition(), std::ref(*itr));
        }

        QuadTree<OrgRef>::Draw(m_rootNode, std::ref(m_window));
    }

    void Manager::ManageCollisions()
    {
        Benchmark<std::chrono::microseconds> bm(__func__);

        for (int i = 0; i < m_nonCognitiveOrgs.size(); i++)
        {
            m_nonCognitiveOrgs[i].Draw(std::ref(m_window));

            auto itr = m_cognitiveOrgs.begin();
            while (itr != m_cognitiveOrgs.end())
            {
                if (m_nonCognitiveOrgs[i].Intersects(itr->GetDrawableEntity().getGlobalBounds()))
                {
                    if (m_nonCognitiveOrgs[i].IsUntouchable())
                    {
                        itr = m_cognitiveOrgs.erase(itr);
                    }
                    else
                    {
                        itr++;
                    }
                }
                else
                {
                    itr++;
                }
            }
        }
    }

    void Manager::DrawOrganisms()
    {
        for (int i = 0; i < m_nonCognitiveOrgs.size(); i++)
        {
            m_nonCognitiveOrgs[i].Draw(std::ref(m_window));
        }

        for (auto &org : m_cognitiveOrgs)
        {
            org.Update();
            org.Draw(std::ref(m_window));
        }
    }

    void Manager::RunMainLoop()
    {
        auto waitSpan = 15s;
        auto begin = std::chrono::steady_clock::now();
        while (m_window.isOpen())
        {
            Benchmark<std::chrono::microseconds> bm(__func__);

            m_window.clear(sf::Color::Black);

            ManageCollisions();
            GenerateTree();

            // std::this_thread::sleep_for(2000ms);

            while (m_window.pollEvent(m_event))
            {
                if (m_event.type == sf::Event::Closed)
                {
                    m_window.close();
                }
                if (m_event.type == sf::Event::KeyPressed)
                {
                    if (m_event.key.code == sf::Keyboard::Escape)
                    {
                        m_window.close();
                    }
                }
                if (m_event.type == sf::Event::MouseButtonPressed)
                {
                    if (m_event.mouseButton.button == sf::Mouse::Button::Left)
                    {
                        QuadTree<OrgRef>::Display(m_rootNode);
                    }

                    if (m_event.mouseButton.button == sf::Mouse::Button::Right)
                    {
                        QuadTree<OrgRef>::FindPoint(m_rootNode, sf::Vector2f(sf::Mouse::getPosition(m_window)));
                    }
                }
            }

            DrawOrganisms();

            auto end = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - begin);

            if (duration >= waitSpan)
            {
                InitCognitiveEntities();
                std::unordered_map<Common::GenomeSequence, float> mpOfSequences;

                for (auto &itr : m_cognitiveOrgs)
                {
                    mpOfSequences[itr.GetGenomeSequence()]++;
                }

                m_genePool.resetProbability(mpOfSequences);
                begin = std::chrono::steady_clock::now();
                mpOfSequences.clear();
            }

            m_window.display();
        }
    }

}