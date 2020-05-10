/*************************************************************************
> File Name: ChampionEnums.hpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Enumeration of the champion stat data.
> Created Time: 2020/05/05
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_CHAMPION_ENUMS_HPP
#define TFAT_CHAMPION_ENUMS_HPP
#include <string>

namespace TFAT {

    enum class ChampionStatTag 
    {
#define X(a) a
#include <TFAT/Enum/ChampionStatTagEnum.def>
#undef X
    };

    const std::string CHAMPION_STAT_TAG_STR[] 
    {
#define X(a) #a
#include <TFAT/Enum/ChampionStatTagEnum.def>
#undef X
    };

    enum class ChampionOrigin
    {
#define X(a) a
#include <TFAT/Enum/ChampionOriginEnum.def>
#undef X
    };

    const std::string CHAMPION_ORIGIN_STR[]
    {
#define X(a) #a
#include <TFAT/Enum/ChampionOriginEnum.def>
#undef X
    };


    enum class ChampionType
    {
#define X(a) a
#include <TFAT/Enum/ChampionTypeEnum.def>
#undef X
    };

    const std::string CHAMPION_TYPE_STR[]
    {
#define X(a) #a
#include <TFAT/Enum/ChampionTypeEnum.def>
#undef X
    };
    
    enum class ChampionSkillType
    {
#define X(a) a
#include <TFAT/Enum/ChampionSkillTypeEnum.def>
#undef X 
    };

    const std::string CHAMPION_SKILL_TYPE_STR[]
    {
#define X(a) #a
#include <TFAT/Enum/ChampionSkillTypeEnum.def>
#undef X 
    };
}

#endif