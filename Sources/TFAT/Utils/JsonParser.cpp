/*************************************************************************
> File Name: JsonParser.cpp
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Json parsing
> Created Time: 2020/04/15
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/

#include <TFAT/Utils/JsonParser.hpp>
#include <cassert>
#include <fstream>

namespace TFAT {

    JsonParser::JsonParser()
    {
        //! Do nothing.
    }

    JsonParser::JsonParser(const std::string& path)
    {
        bool parseResult = LoadJson(path);
        assert(parseResult);
    }

    JsonParser::~JsonParser()
    {
        //! Do nothing.
    }

    bool JsonParser::LoadJson(const std::string& path)
    {
        std::ifstream jsonData(path);
        
        if (jsonData.is_open() == false)
            return false;

        auto json = nlohmann::json::parse(jsonData);
        OnLoadJson(json);
        return true;
    }

}