/*************************************************************************
> File Name: ChampionParser.cpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Json parsing
> Created Time: 2020/04/19
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/

#include <TFAT/Utils/ChampionParser.hpp>
#include <TFAT/Utils/Macros.hpp>
#include <TFAT/Champion/Champion.hpp>
#include <TFAT/Enum/ChampionEnums.hpp>
#include <iostream>

namespace TFAT {
    ChampionParser::ChampionParser()
    {
        //! Do nothing.
    }

    ChampionParser::ChampionParser(const std::string& path)
        : JsonParser(path)
    {
        //! Do nothing
    }

    ChampionParser::~ChampionParser()
    {
        _champions.clear();
    }

    ChampionPtr ChampionParser::GetChampionByName(const std::string& name) const
    {
        UNUSED_VARIABLE(name);
        return nullptr;
    }   

    std::vector<ChampionPtr> ChampionParser::GetChampionsByOrigin(const std::string& name) const
    {
        UNUSED_VARIABLE(name);
        return std::vector<ChampionPtr>();
    }

    std::vector<ChampionPtr> ChampionParser::GetChampionsByType(const std::string& name) const
    {
        UNUSED_VARIABLE(name);
        return std::vector<ChampionPtr>();
    }

    void ChampionParser::OnLoadJson(const nlohmann::json& json)
    {
        _champions.reserve(json.size());

        for (auto& championData : json)
        {
            const auto name         = championData["name"].get<std::string>();
            const auto armor        = championData["armor"].get<float>();
            const auto attack       = championData["attack"].get<float>();
            const auto cost         = championData["cost"].get<float>();
            const auto dps          = championData["dps"].get<float>();
            const auto manaCost     = championData["mana_cost"].get<float>();
            const auto range        = championData["range"].get<float>();
            const auto rangeSM      = championData["range_sm"].get<float>();
            const auto resistance   = championData["resistance"][0].get<float>();
            const auto speed        = championData["speed"].get<float>();

            const std::array<float, 3> health = {
                championData["health"][0].get<float>(),
                championData["health"][1].get<float>(),
                championData["health"][2].get<float>(),
            };                

            std::vector<ChampionOrigin> origins;
            std::vector<ChampionType> types;
            ChampionSkill skill;

            for (auto& originData : championData["origin"])
            {
                origins.push_back(StrToEnum<ChampionOrigin>(originData.get<std::string>()));
            }

            for (auto& typeData : championData["type"])
            {
                types.push_back(StrToEnum<ChampionType>(typeData.get<std::string>()));
            }

            skill.name = championData["skill"]["name"].get<std::string>();
            std::vector<ChampionSkillTag> skillTags;
            
            for (auto& skillTagData : championData["skill"]["tags"])
            {
                ChampionSkillTag tempTag;
                tempTag.type = StrToEnum<ChampionSkillType>(skillTagData["name"].get<std::string>());
                //! tempTag.bonus = std::array<float, 3> {
                //!     skillTagData["bonus"][0].get<float>(),
                //!     skillTagData["bonus"][1].get<float>(),
                //!     skillTagData["bonus"][2].get<float>(),
                //! };          
                skillTags.push_back(tempTag);      
            }
            skill.tags = skillTags;
            
            ChampionPtr champion = std::make_shared<Champion>();
            champion->name = name;
            champion->health = health;
            champion->origins = origins;
            champion->types = types;
            champion->skill = skill;
            champion->gameTag[ChampionStatTag::ARMOR] = armor;
            champion->gameTag[ChampionStatTag::ATTACK] = attack;
            champion->gameTag[ChampionStatTag::COST] = cost;
            champion->gameTag[ChampionStatTag::DPS] = dps;
            champion->gameTag[ChampionStatTag::MANA_COST] = manaCost;
            champion->gameTag[ChampionStatTag::RANGE] = range;
            champion->gameTag[ChampionStatTag::RANGE_SM] = rangeSM;
            champion->gameTag[ChampionStatTag::RESISTANCE] = resistance;
            champion->gameTag[ChampionStatTag::SPEED] = speed;

            _champions.push_back(champion);
        }
    }

}