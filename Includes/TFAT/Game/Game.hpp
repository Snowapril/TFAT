/*************************************************************************
> File Name: Game.hpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Game manager class which control whole process of the game.
> Created Time: 2020/06/24
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_GAME_H
#define TFAT_GAME_H

#include <memory>
#include <TFAT/Model/Player.hpp>

namespace TFAT {

    //!
    //! \brief Base class for Champion object.
    //!
    //! This class contains several attribute(piece info, turn, etc..)
    //! and methods(attack, advance, etc..).
    //! 
    class Game final
    {
    public:
        //! Default constructor.
        Game();

        //! Default destructor.
        ~Game();
        
    protected:
    private:
        std::array<PlayerPtr, 8> _players;
    };

    using GamePtr = std::shared_ptr<Game>;
}

#endif