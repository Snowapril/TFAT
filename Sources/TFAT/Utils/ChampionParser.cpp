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
#include <TFAT/Champion/ChampionStat.hpp>
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
            ChampionStat stat;
            stat.name = championData["name"].is_null() ? "" : championData["name"].get<std::string>();
            stat.armor = championData["armor"].get<float>();
            stat.attack = championData["attack"].get<float>();
            stat.dps = championData["dps"].get<float>();
            stat.skillCost = championData["mana_cost"].get<int>();
            stat.cost = championData["cost"].get<int>();
            //const float health = championData["armor"].get<int>();


            //card->gameTags = gameTags;
            //card->gameTags[GameTag::ATK] = attack;
            //card->gameTags[GameTag::CARDRACE] = cardRace;
            //card->gameTags[GameTag::CARD_SET] = cardSet;
            //card->gameTags[GameTag::CARDTYPE] = cardType;
            //card->gameTags[GameTag::CLASS] = cardClass;
            //card->gameTags[GameTag::COLLECTIBLE] = collectible;
            //card->gameTags[GameTag::COST] = cost;
            //card->gameTags[GameTag::DAMAGE] = 0;
            //card->gameTags[GameTag::DURABILITY] = durability;
            //card->gameTags[GameTag::FACTION] = faction;
            //card->gameTags[GameTag::ARMOR] = armor;
            //card->gameTags[GameTag::HEALTH] = health;
            //card->gameTags[GameTag::RARITY] = rarity;
            //card->gameTags[GameTag::SPELLPOWER] = spellPower;
            //card->gameTags[GameTag::OVERLOAD] = overload;

            _champions.push_back(std::make_shared<Champion>(stat));
        }
    }

}