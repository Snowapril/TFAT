/*************************************************************************
> File Name: Player.hpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Player class which have game status and etc.
> Created Time: 2020/06/24
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_PLAYER_H
#define TFAT_PLAYER_H

#include <memory>

namespace TFAT {

    //!
    //! \brief Player class for represent game status 
    //!
    class Player final
    {
    public:
        //! Default constructor.
        Player();

        //! Default destructor.
        ~Player();
        
    protected:
    private:
    };

    using PlayerPtr = std::shared_ptr<Player>;
}

#endif