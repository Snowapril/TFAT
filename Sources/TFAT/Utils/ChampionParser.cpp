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
#include <TFAT/Champion/ChampionStat.hpp>

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
        //! Do nothing
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
        UNUSED_VARIABLE(json);
    }

}