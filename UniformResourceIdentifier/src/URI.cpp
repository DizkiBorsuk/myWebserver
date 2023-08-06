#include <URI/URI.hpp>

namespace URI
{
    // class with private properties of URI 
    struct URI::Implementation
    {   
        std::string scheme; 
        std::string host; 
        std::vector<std::string> path; 
    };

    URI::~URI() = default; // destructor set to default 

    URI::URI() : 
        pImpl_(new Implementation) // pointer to implementation class allocated at heap 
    {

    }
    

    bool URI::parseString(const std::string &uriString)
    {
        // parsing url adress to scheme, host and path parts 
        const auto schemeEnd = uriString.find(":"); 
        pImpl_->scheme = uriString.substr(0, schemeEnd); // assign to scheme in implementation class thru pointer
        auto restOfURL = uriString.substr(schemeEnd+1); 


        if(restOfURL.substr(0,2) =="//")
        {
            const auto authorityEnd = restOfURL.find('/', 2); // find / starting from // 
            pImpl_->host = restOfURL.substr(2, authorityEnd -2); 
            restOfURL = restOfURL.substr(authorityEnd); 
        } 
        else 
        {
            pImpl_->host.clear(); 
        }

        pImpl_->path.clear(); 

        if(!restOfURL.empty())
        {
            while(true) 
            {
                auto pathDelimeter = restOfURL.find('/'); 
                if(pathDelimeter == std::string::npos) //if finding path delimeter fails
                {
                    pImpl_->path.emplace_back(restOfURL); 
                    break; 
                }
                else 
                {
                    pImpl_->path.emplace_back(restOfURL.begin(), restOfURL.begin()+pathDelimeter); 
                }
                
                restOfURL = restOfURL.substr(pathDelimeter+1); 
            }
            
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
        return pImpl_->path; 
    }

}