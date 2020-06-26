/*************************************************************************
> File Name: SkillTag.hpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Champion skill tag data wrapper.
> Created Time: 2020/06/26
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_CHAMPION_SKILL_TAG_H
#define TFAT_CHAMPION_SKILL_TAG_H

#include <TFAT/Enum/ChampionEnums.hpp>
#include <array>

namespace TFAT {

    struct ChampionSkillTag
    {
        ChampionSkillType type;
        std::array<float, 3> bonus;
    };
}

#endif