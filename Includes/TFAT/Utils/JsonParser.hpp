/*************************************************************************
> File Name: JsonParser.h
> Project Name: TFAT
> This code is based on baba-is-auto that was created by Chris Ohk
> References: https://github.com/utilforever/baba-is-auto
> Purpose: Json parsing
> Created Time: 2020/04/15
> Copyright (c) 2020, Ji-Hong snowapril
*************************************************************************/
#ifndef TFAT_JSONPARSER_H
#define TFAT_JSONPARSER_H

#include <nlohmann/json.hpp>
#include <memory>
#include <string>

namespace TFAT {

    //!
    //! \brief Parsing json data.
    //!
    class JsonParser
    {
    public:
        //! Default constructor.
        JsonParser();

        //! Constructor with json file path.
        JsonParser(const std::string& path);

        //! Default destructor.
        virtual ~JsonParser();

        bool LoadJson(const std::string& path);
        
    protected:
        virtual void OnLoadJson(const nlohmann::json& json) = 0;
    private:
    };

    using JsonParserPtr = std::shared_ptr<JsonParser>;
}

#endif