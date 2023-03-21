#include "Entity.hpp"
#include "IActionFactory.hpp"

using namespace NaturalSelection::Brain;
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

    // std::vector<Entity<sf::RectangleShape>> orgs;
    std::vector<Entity<sf::CircleShape>> orgs;

    BrainProxy proxy;

    for (auto i = 0; i < 10000; i++)
    {
        Entity<sf::CircleShape> org(std::ref(proxy));
        // Entity<sf::RectangleShape> org(std::ref(proxy));

        org.Spawn();
        orgs.emplace_back(org);
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
        for (auto &org : orgs)
        {
            org.Update();
            org.Draw(std::ref(window));
        }
        window.display();
    }
}

int main()
{
    srand(time(nullptr));
    InitializeLogging();
    testRun();

    return 0;
}