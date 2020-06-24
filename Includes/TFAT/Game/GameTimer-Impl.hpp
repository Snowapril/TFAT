/*************************************************************************
> File Name: GameTimer-Impl.hpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Game manager class which control whole process of the game.
> Created Time: 2020/06/24
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_GAME_TIMER_IMPL_H
#define TFAT_GAME_TIMER_IMPL_H

#include <thread>

namespace TFAT {

    template <typename... Args>
    GameTimer<Args...>::GameTimer()
    {
        //! Do nothing.
    }

    template <typename... Args>
    GameTimer<Args...>::~GameTimer()
    {
        //! Do nothing.
    }

    template <typename... Args>
    GameTimer<Args...>& GameTimer<Args...>::operator+=(const CallbackType& callback)
    {
        _callbacks.push_back(callback);
        return *this;
    }
    
    template <typename... Args>
    template <typename Rep, typename Period>
    bool GameTimer<Args...>::StartTimer(const std::chrono::duration<Rep, Period>& duration, Args... args)
    {
        //! sleep for duration this thread.
        std::this_thread::sleep_for(duration);

        //! After duration time elapsed...
        bool result = true;
        for (auto& callback : _callbacks)  
            result = result && callback(std::forward<Args>(args)...);
        return result;
    }
}

#endif