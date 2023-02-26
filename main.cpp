#include <iostream>
#include "EntityFactory.hpp"
#include "OrganismFactory.hpp"
#include "BrainProxy.hpp"
#include <math.h>

using namespace SmartEvolution::Common;
using namespace SmartEvolution::Organism;
using namespace SmartEvolution::Brain;

void testOrganismFactory()
{
    std::unique_ptr<IEntityFactory> entityFactory = std::make_unique<EntityFactory>();
    std::unique_ptr<IOrganismFactory> organismFactory = std::make_unique<OrganismFactory>();
    std::vector<Organism> orgs;
    for (auto i = 0; i < 10; i++)
    {
        orgs.emplace_back(organismFactory->getOrganism(entityFactory->getEntity(EntityType::Living, GenomeSequence("10001"))));
    }
}

void testBrainProxy()
{
    std::unique_ptr<IBrainProxy> brainProxy = std::make_unique<BrainProxy>();
    for (auto i = 0; i < 10; i++)
    {
        std::cout << Utility::translateReaction(brainProxy->getReactionToStimuli("10101", StimuliType::Mechanical)) << std::endl;
    }
}

void testRun()
{
    auto sharedPtrWindow = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(Width, Height), WindowName);

    std::unique_ptr<IEntityFactory> entityFactory = std::make_unique<EntityFactory>();
    std::unique_ptr<IOrganismFactory> organismFactory = std::make_unique<OrganismFactory>();
    std::vector<Organism> orgs;
    std::unique_ptr<IBrainProxy> brainProxy = std::make_unique<BrainProxy>();
    for (auto i = 0; i < 10; i++)
    {
        orgs.emplace_back(organismFactory->getOrganism(entityFactory->getEntity(EntityType::Living, GenomeSequence("11000"))));
    }

    while (sharedPtrWindow->isOpen())
    {
        sf::Event event;
        sharedPtrWindow->clear(sf::Color::Black);

        while (sharedPtrWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                sharedPtrWindow->close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    sharedPtrWindow->close();
                }
            }
        }
        for (auto &org : orgs)
        {
            auto reaction = brainProxy->getReactionToStimuli(org.m_entity->getGenomeSequence(), StimuliType::Mechanical);
            auto pos = org.getPosition();
            switch (reaction)
            {
            case ReactionType::Invalid:
                break;

            case ReactionType::MvN:
                pos = {pos.x, pos.y - 1};
                org.setPosition(pos);
                break;
            case ReactionType::MvS:
                pos = {pos.x, pos.y + 1};
                org.setPosition(pos);
                break;
            case ReactionType::MvE:
                pos = {pos.x + 1, pos.y};
                org.setPosition(pos);
                break;
            case ReactionType::MvW:
                pos = {pos.x - 1, pos.y};
                org.setPosition(pos);
                break;
            case ReactionType::MvR:

                pos = {pos.x + Utility::getRandomNumberInRange(0, 1) * static_cast<int>(std::pow(-1, Utility::getRandomNumberInRange(0, 1))),

                       pos.y + Utility::getRandomNumberInRange(0, 1) * static_cast<int>(std::pow(-1, Utility::getRandomNumberInRange(0, 1)))};
                org.setPosition(pos);
                break;
            }
            sharedPtrWindow->draw(org);
        }
        sharedPtrWindow->display();
    }
}

int main()
{
    testRun();
    // testOrganismFactory();
    // testBrainProxy();
    return 0;
}