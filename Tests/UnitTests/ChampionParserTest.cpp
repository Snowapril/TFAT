#include "pch.h"

#include <TFAT/Champion/Champion.hpp>
#include <TFAT/Utils/ChampionParser.hpp>
using namespace TFAT;

TEST_CASE("Json parsing test")
{
    ChampionParser parser;
    bool result = parser.LoadJson(RESOURCE_DIR "champions.json");
    
    CHECK(result == true);
}