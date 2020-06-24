#include "pch.h"

#include <TFAT/Game/GameTimer.hpp>
using namespace TFAT;

TEST_CASE("GameTimer test")
{
    GameTimer<int, int> timer;

    timer += [](int a, int b){
        return static_cast<bool>(a + b);
    };

    bool result = timer.StartTimer(std::chrono::milliseconds(1000), 3, 10);
    CHECK(result == true);
}