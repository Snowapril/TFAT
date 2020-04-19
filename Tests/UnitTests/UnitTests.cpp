// Copyright (c) 2020 Jihong Shin

// I am making my contributions/submissions to this project solely in our
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#undef NEAR

#include <TFAT/Champion/Champion.hpp>
#include <TFAT/Utils/ChampionParser.hpp>
using namespace TFAT;

TEST_CASE("Simple test")
{
    Champion Champion;
    //!CHECK();
}

TEST_CASE("Json parsing test")
{
    ChampionParser parser;
    bool result = parser.LoadJson(RESOURCE_DIR "champions.json");

    CHECK(result == true);
}