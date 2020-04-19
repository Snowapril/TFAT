/*************************************************************************
> File Name: ChampionParser.h
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Json parsing
> Created Time: 2020/04/19
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_CHAMPIONPARSER_H
#define TFAT_CHAMPIONPARSER_H

#include <TFAT/Champion/Champion.hpp>
#include <TFAT/Utils/JsonParser.hpp>
#include <string>
#include <vector>
#include <memory>

namespace TFAT {


    //!
    //! \brief Parsing json data.
    //!
    class ChampionParser final : public JsonParser
    {
    public:
        //! Default constructor.
        ChampionParser();

        //! Constructor with json file path.
        ChampionParser(const std::string& path);
        
        //! Default destructor.
        virtual ~ChampionParser();

        //! Get unique champion instance by it's name.
        ChampionPtr GetChampionByName(const std::string& name) const;

        //! Get champion vector by origin name
        std::vector<ChampionPtr> GetChampionsByOrigin(const std::string& name) const;

        //! Get champion vector by type name
        std::vector<ChampionPtr> GetChampionsByType(const std::string& name) const;
    protected:
        void OnLoadJson(const nlohmann::json& json) override;
    private:
    };

    using ChampionParserPtr = std::shared_ptr<ChampionParser>;
}

#endif