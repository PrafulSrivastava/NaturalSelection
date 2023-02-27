#include <iostream>
#include <math.h>
#include "IActionFactory.hpp"
#include "Organism.hpp"
#include <functional>

using namespace SmartEvolution;
using namespace SmartEvolution::Common;
using namespace SmartEvolution::Action;
using namespace SmartEvolution::Entity;

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

void TestActions()
{
    Log(Log::INFO, __func__);

    Organism org;
    std::reference_wrapper<Organism> ref_org = std::ref(org);

    IActionFactory cmd(ref_org);

    Log(Log::INFO, "{X, Y} :", "{", org.getPosition().x, ",", org.getPosition().y, "}");
    cmd.execute<Operation::Move_North>();
    Log(Log::INFO, "{X, Y} :", "{", org.getPosition().x, ",", org.getPosition().y, "}");
    cmd.execute<Operation::Move_East>();
    Log(Log::INFO, "{X, Y} :", "{", org.getPosition().x, ",", org.getPosition().y, "}");
    cmd.execute<Operation::Move_West>();
    Log(Log::INFO, "{X, Y} :", "{", org.getPosition().x, ",", org.getPosition().y, "}");
    cmd.execute<Operation::Move_South>();
    Log(Log::INFO, "{X, Y} :", "{", org.getPosition().x, ",", org.getPosition().y, "}");
    cmd.execute<Operation::Move_Random>();
    Log(Log::INFO, "{X, Y} :", "{", org.getPosition().x, ",", org.getPosition().y, "}");

    cmd.execute<Operation::Change_Color_Red>();
}

int main()
{
    InitializeLogging();
    TestActions();

    return 0;
}