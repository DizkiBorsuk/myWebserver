#pragma once 
#include <memory>
#include <string> 
#include <vector>
#include <iostream>

namespace URI
{
    class URI
    {
    public: 
        URI();
        ~URI(); 
        // delete move and copy constructors/operators
        URI(const URI&) = delete;  
        URI(URI&&) = delete;
        URI& operator=(const URI&) = delete; 
        URI& operator=(const URI&&) = delete; 

        // methods 
        bool parseString(const std::string &uriString); 
        std::string getHost() const; // method only returns string, it won't change anything co use const 
        std::string getScheme() const;
        std::vector<std::string> getPath() const;

    private: 
        // pointer to implementation patern 
        //https://en.cppreference.com/w/cpp/language/pimpl
        struct Implementation; 
        std::unique_ptr<struct Implementation> pImpl_; 

    }; 
}