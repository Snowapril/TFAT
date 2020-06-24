/*************************************************************************
> File Name: GameTimer.hpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Game manager class which control whole process of the game.
> Created Time: 2020/06/24
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_GAME_TIMER_H
#define TFAT_GAME_TIMER_H

#include <functional>
#include <memory>
#include <vector>
#include <chrono>

namespace TFAT {

    //!
    //! \brief Base class for Champion object.
    //!
    //! This class contains several attribute(piece info, turn, etc..)
    //! and methods(attack, advance, etc..).
    //! 
    template <typename... Args>
    class GameTimer final
    {
    public:
        using CallbackType = std::function<bool(Args...)>;
        //! Default constructor.
        GameTimer();

        //! Default destructor.
        ~GameTimer();

        //! Add the callback function to the timer.
        //! first-in callback function will be executed first.
        GameTimer& operator+=(const CallbackType& callback);

        //! Start the timer. After duration, queued events will be executed.
        template <typename Rep, typename Period>
        bool StartTimer(const std::chrono::duration<Rep, Period>& duration, Args... args);
    protected:
    private:
        std::vector<CallbackType> _callbacks;
    };

    template <typename... Args>
    using GameTimerPtr = std::shared_ptr<GameTimer<Args...>>;
}

#include <TFAT/Game/GameTimer-Impl.hpp>

#endif