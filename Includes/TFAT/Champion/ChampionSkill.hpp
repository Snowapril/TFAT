/*************************************************************************
> File Name: ChampionSkill.hpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Champion skill data wrapper.
> Created Time: 2020/06/26
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_CHAMPION_SKILL_H
#define TFAT_CHAMPION_SKILL_H

#include <TFAT/Enum/ChampionEnums.hpp>
#include <TFAT/Champion/ChampionSkillTag.hpp>
#include <memory>
#include <vector>
#include <array>

namespace TFAT {

    //!
    //! \brief Base class for Champion object.
    //!
    //! This class contains several attribute(piece info, turn, etc..)
    //! and methods(attack, advance, etc..).
    //! 
    struct ChampionSkill final
    {
        std::string name;
        std::vector<ChampionSkillTag> tags;
    };
}

#endif