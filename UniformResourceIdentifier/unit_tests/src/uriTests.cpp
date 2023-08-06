#include <gtest/gtest.h>
#include <URI/URI.hpp>
#include <vector>
#include <string>

TEST(uriTests, ParseFromString)
{
    // Test for checking if parsing of string works  
    URI::URI uri; 
    // first round of tests 

    ASSERT_TRUE(uri.parseString("http://www.mywebsite.com/foo/what")); // check if parsing succeded 
    ASSERT_EQ("http", uri.getScheme()); // check if scheme part was done corectlly 
    ASSERT_EQ("www.mywebsite.com", uri.getHost());// check if
    ASSERT_EQ((std::vector<std::string> {"", "foo", "what"}), uri.getPath());  

    // second round of tests 
    ASSERT_TRUE(uri.parseString("urn://www.fishywebcryptoscam.com/bitcoin/who")); // check if parsing succeded 
    ASSERT_EQ("urn", uri.getScheme()); // check if scheme part was done corectlly 
    ASSERT_EQ("www.fishywebcryptoscam.com", uri.getHost()); // check if
    //ASSERT_EQ((std::vector<std::string> {"", "bitcoin", "who"}), uri.getPath()); 

}


