#include <URI/URI.hpp>

namespace URI
{
    struct URI::Implementation
    {   };

    URI::~URI() = default; // destructor set to default 

    URI::URI() : pImpl_(new Implementation)
    {

    }
    




}