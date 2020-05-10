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
            const std::string id = championData["id"].get<std::string>();

            const std::string name = championData["name"].is_null()
                                         ? ""
                                         : championData["name"].get<std::string>();

            ChampionPtr champion = std::make_shared<Champion>();
            champion->id = id;
            champion->name = name;
            //Card* card = new Card();
            //card->id = id;
            //card->dbfID = dbfID;
            //card->name = name;
            //card->text = text;

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

            //cards.emplace_back(card);
            std::cout << name << std::endl;
        }
    }

}