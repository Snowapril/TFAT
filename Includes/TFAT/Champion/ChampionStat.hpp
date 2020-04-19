/*************************************************************************
> File Name: ChampionParser.cpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Json parsing
> Created Time: 2020/04/19
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_CHAMPION_STAT_HPP
#define TFAT_CHAMPION_STAT_HPP

#include <string>
#include <vector>

namespace TFAT
{
    struct SkillTag
    {
        std::string skillType;
        float skillBonus[3];
    };
            
    struct Skill
    {
        std::string skillName;
        std::vector<SkillTag> skillTags;
    };

    struct ChampionStat
    {
        std::string name;
        int health[3];
        int skillCost;
        int cost;
        float attack;
        float dps;
        float range;
        int rangeLevel;
        float armor;
        float resistance;
        float speed;
        std::string origin;
        std::string type;
        Skill skill;
    };
};

#endif