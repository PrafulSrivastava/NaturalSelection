#include "Manager.hpp"

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
    Manager manager;
    manager.Init();
    manager.RunMainLoop();
}

int main()
{
    srand(time(nullptr));
    InitializeLogging();
    testRun();
    return 0;
}