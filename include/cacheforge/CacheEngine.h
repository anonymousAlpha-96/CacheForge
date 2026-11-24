
/*##########################################################################################################
#copyright (c) 2026 reserved
#Author: Ankit
#Date: 2026/24/11
#Description: CacheEngine.h for CacheForge project
##########################################################################################################*/

//=========================================================================================================
// 21-Nov-26 : Task 01 : initial commits 
//=========================================================================================================
#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <optional>

class CacheEngine
{
    public:

    void set(const std::string& key, const std::string& value);
    std::optional<std::string> get(const std::string& key) const;    
    bool remove(const std::string& key);
    bool exists(const std::string& key) const;

    private:
    std::unordered_map<std::string, std::string> cache_;
};