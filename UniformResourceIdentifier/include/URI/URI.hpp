#pragma once 
#include <memory>

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


    private: 
        // pointer to implementation patern 
        //https://en.cppreference.com/w/cpp/language/pimpl
        struct Implementation; 
        std::unique_ptr<struct Implementation> pImpl_; 

    }; 
}