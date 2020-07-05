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
#include <algorithm>
#include <cctype>
#include <iterator>

namespace TFAT {

    enum class ChampionStatTag 
    {
#define X(a) a,
#include <TFAT/Enum/ChampionStatTagEnum.def>
#undef X
        INVALID
    };

    const std::string CHAMPION_STAT_TAG_STR[] 
    {
#define X(a) #a,
#include <TFAT/Enum/ChampionStatTagEnum.def>
#undef X
    };

    enum class ChampionOrigin
    {
#define X(a) a,
#include <TFAT/Enum/ChampionOriginEnum.def>
#undef X
        INVALID
    };

    const std::string CHAMPION_ORIGIN_STR[]
    {
#define X(a) #a,
#include <TFAT/Enum/ChampionOriginEnum.def>
#undef X
    };


    enum class ChampionType
    {
#define X(a) a,
#include <TFAT/Enum/ChampionTypeEnum.def>
#undef X
        INVALID
    };

    const std::string CHAMPION_TYPE_STR[]
    {
#define X(a) #a,
#include <TFAT/Enum/ChampionTypeEnum.def>
#undef X
    };
    
    enum class ChampionSkillType
    {
#define X(a) a,
#include <TFAT/Enum/ChampionSkillTypeEnum.def>
#undef X 
        INVALID
    };

    const std::string CHAMPION_SKILL_TYPE_STR[]
    {
#define X(a) #a,
#include <TFAT/Enum/ChampionSkillTypeEnum.def>
#undef X 
    };

    template <typename Enum>
    Enum StrToEnum(const std::string& str)
    {
        static_assert("No implementation exists.");
    }

#define STR2ENUM(ENUM, STR_ARRAY) \
    template<> \
    inline ENUM StrToEnum(const std::string& str) \
    { \
        std::string upperStr; \
        std::transform(str.cbegin(), str.cend(), std::back_inserter(upperStr), [](unsigned char c) -> unsigned char { \
            if (std::isalpha(c)) return static_cast<unsigned char>(std::toupper(c)); \
            else if (c == ' ' || c == '-') return '_'; \
            else return c; \
        }); \
        for (int i = 0; i < static_cast<int>(ENUM::INVALID); ++i) \
        { \
            if (upperStr == STR_ARRAY[i]) \
                return static_cast<ENUM>(i); \
        } \
        return ENUM::INVALID; \
    }

STR2ENUM(ChampionOrigin, CHAMPION_ORIGIN_STR)
STR2ENUM(ChampionSkillType, CHAMPION_SKILL_TYPE_STR)
STR2ENUM(ChampionStatTag, CHAMPION_STAT_TAG_STR)
STR2ENUM(ChampionType, CHAMPION_TYPE_STR)
}

#endif
