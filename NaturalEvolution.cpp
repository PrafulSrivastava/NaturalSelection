#include "CognitiveEntity.hpp"
#include "NonCognitiveEntity.hpp"
#include "IActionFactory.hpp"
#include "QuadTree.hpp"

using namespace NaturalSelection::Brain;
using namespace NaturalSelection::Manager;
using namespace NaturalSelection::Entity;
using namespace NaturalSelection::Common;
using namespace NaturalSelection::Trace;
using namespace NaturalSelection::Action;

void InitializeLogging()
{
    ConfigParser::GetInstance().LoadConfig();
    std::ofstream fs;

    if (ConfigParser::GetInstance().LoggingType() == "File")
    {
        fs.open(ConfigParser::GetInstance().LogFilePath());

        Logger::init<std::ofstream>(ConfigParser::GetInstance().LoggingLevel(), &fs);
    }
    else if (ConfigParser::GetInstance().LoggingType() == "Console")
    {
        Logger::init<std::ostream>(ConfigParser::GetInstance().LoggingLevel());
    }
    else if (ConfigParser::GetInstance().LoggingType() == "SStream")
    {
        Logger::init<std::stringstream>(ConfigParser::GetInstance().LoggingLevel());
    }
}

void testRun()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), WINDOW_NAME);

    std::vector<NonCognitiveEntity<sf::RectangleShape>> nonCognitiveOrgs;

    NonCognitiveEntity<sf::RectangleShape> nBoundry(NonCognitiveEntityType::NorthBoundry);
    NonCognitiveEntity<sf::RectangleShape> sBoundry(NonCognitiveEntityType::SouthBoundry);
    NonCognitiveEntity<sf::RectangleShape> eBoundry(NonCognitiveEntityType::EastBoundry);
    NonCognitiveEntity<sf::RectangleShape> wBoundry(NonCognitiveEntityType::WestBoundry);

    nonCognitiveOrgs.push_back(nBoundry);
    nonCognitiveOrgs.push_back(sBoundry);
    nonCognitiveOrgs.push_back(eBoundry);
    nonCognitiveOrgs.push_back(wBoundry);

    BrainProxy proxy;
    std::vector<CognitiveEntity<sf::CircleShape>> cognitiveOrgs;

    for (auto i = 0; i < 500; i++)
    {
        CognitiveEntity<sf::CircleShape> org(std::ref(proxy));
        org.Spawn();
        cognitiveOrgs.emplace_back(org);
    }

    for (int i = 0; i < nonCognitiveOrgs.size(); i++)
    {
        nonCognitiveOrgs[i].Spawn();
    }

    while (window.isOpen())
    {
        sf::Event event;
        window.clear(sf::Color::Black);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }
        auto root = std::make_shared<Node<int>>(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT));

        for (auto i = 0; i < 500; i++)
        {
            Insert<int>(root, cognitiveOrgs[i].GetPosition(), i);
        }

        Draw<int>(root, std::ref(window));

        for (auto &org : cognitiveOrgs)
        {
            org.Update();
            org.Draw(std::ref(window));
        }

        root.reset();

        for (int i = 0; i < nonCognitiveOrgs.size(); i++)
        {
            nonCognitiveOrgs[i].Draw(std::ref(window));
        }

        window.display();
    }
}

int main()
{
    srand(time(nullptr));
    InitializeLogging();
    testRun();
    // testQuadTree();
    return 0;
}