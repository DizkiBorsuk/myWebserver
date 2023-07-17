#include <URI/URI.hpp>

namespace URI
{
    struct URI::Implementation
    {   };

    URI::~URI() = default; // destructor set to default 

    URI::URI() : pImpl_(new Implementation)
    {

    }
    

    bool URI::parseString(const std::string &uriString)
    {
        return false; 
    }
    std::string URI::getHost() const 
    {
        return ""; 
    } 
    std::string URI::getScheme() const
    {
        return ""; 

    }
    std::vector<std::string> URI::getPath() const
    {
        return {}; 
    }

}