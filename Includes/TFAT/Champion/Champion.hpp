/*************************************************************************
> File Name: Champion.h
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Base class of the TFAT Champions.
> Created Time: 2020/04/15
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_CHAMPION_H
#define TFAT_CHAMPION_H

#include <memory>

namespace TFAT {

    //!
    //! \brief Base class for Champion object.
    //!
    //! This class contains several attribute(piece info, turn, etc..)
    //! and methods(attack, advance, etc..).
    //! 
    class Champion
    {
    public:
        //! Default constructor.
        Champion();

        //! Default destructor.
        virtual ~Champion();

        
    protected:
    private:
    };

    using ChampionPtr = std::shared_ptr<Champion>;
}

#endif