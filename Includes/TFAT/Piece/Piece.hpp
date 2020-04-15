/*************************************************************************
> File Name: Piece.h
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Base class of the TFAT pieces.
> Created Time: 2020/04/15
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_PIECE_H
#define TFAT_PIECE_H

#include <memory>

namespace TFAT {

    //!
    //! \brief Base class for Piece object.
    //!
    //! This class contains several attribute(piece info, turn, etc..)
    //! and methods(attack, advance, etc..).
    //! 
    class Piece
    {
    public:
        //! Default constructor.
        Piece();

        //! Default destructor.
        virtual ~Piece();

    protected:
    private:
    };

    using PiecePtr = std::shared_ptr<Piece>;
}

#endif