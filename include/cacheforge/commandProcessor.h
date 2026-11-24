
/*##########################################################################################################
#copyright (c) 2026 reserved
#Author: Ankit
#Date: 2026/24/11
#Description: commandProcessor.h for CacheForge project
##########################################################################################################*/

//=========================================================================================================
// 24-Nov-26 :Task 01 : Initial commits for commandProcessor.h
//=========================================================================================================
#pragma once

#include "cacheforge/CacheEngine.h"
#include <iostream>
#include <string>

class CommandProcessor
{
    public:

    explicit CommandProcessor(CacheEngine& engine);

    void run();

    private:
    CacheEngine& engine_;
};
