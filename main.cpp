#include "Entity.hpp"

using namespace NaturalSelection::Brain;
using namespace NaturalSelection::Entity;
using namespace NaturalSelection::Common;

int main()
{
    srand(time(nullptr));

    Entity org;
    org.Spawn();
    org.ToString();
    org.Update();
    org.ToString();

    return 0;
}