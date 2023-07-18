#include <URI/URI.hpp>

namespace URI
{
    // class with private properties of URI 
    struct URI::Implementation
    {   
        std::string scheme; 
        std::string host; 
    };

    URI::~URI() = default; // destructor set to default 

    URI::URI() : 
        pImpl_(new Implementation) // pointer to implementation class 
    {

    }
    

    bool URI::parseString(const std::string &uriString)
    {
        const auto schemeEnd = uriString.find(":"); 
        pImpl_->scheme = uriString.substr(0, schemeEnd); // assign to scheme in implementation class thru pointer
        if(uriString.substr(schemeEnd,2) =="//")
        {
            const auto authorityEnd = uriString.find('/', schemeEnd+2); // find / starting from // 
            pImpl_->host = uriString.substr(schemeEnd+2, authorityEnd - (schemeEnd+2)); 
        } 
        else 
        {

        }
        
        return true; 
    }
    std::string URI::getHost() const 
    {
        return pImpl_->host; 
    } 
    std::string URI::getScheme() const
    {
        return pImpl_->scheme; 
    }
    std::vector<std::string> URI::getPath() const
    {
        return {}; 
    }

}