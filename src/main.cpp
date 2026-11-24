
/*##########################################################################################################
#copyright (c) 2026 reserved
#Author: Ankit
#Date: 2026/24/11
#Description: main.cpp for CacheForge project
##########################################################################################################*/

//=========================================================================================================
// 21-Nov-26 : Task 01 : initial commits 
//=========================================================================================================
// 24-Nov-26 :Task 02 : updated command processor to handle the user commands
//=========================================================================================================

#include "cacheforge/CacheEngine.h"
#include "cacheforge/commandProcessor.h"
#include <iostream>

int main()
{
    std::cout << "CacheForge v1.0\n";
    std::cout << "In-memory key-value database starting...\n";
    std::cout << "Type 'help' to see available commands.\n";

    CacheEngine engine;
    CommandProcessor processor(engine);
    processor.run();

    std::cout<< "CacheEngine shutdown successfully!..."<<std::endl;
    

    return 0;
}