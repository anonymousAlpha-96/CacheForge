
/*##########################################################################################################
#copyright (c) 2026 reserved
#Author: Ankit
#Date: 2026/24/11
#Description: commandProcessor.cpp for CacheForge project
##########################################################################################################*/

//=========================================================================================================
// 24-Nov-26 :Task 01 : updated command processor to handle the user commands
//=========================================================================================================

#include "cacheforge/commandProcessor.h"


CommandProcessor::CommandProcessor(CacheEngine& engine): engine_(engine){}

void CommandProcessor::run()
{
    std::string command;
    while(true)
    {
        std::cout<<"\nCacheForge> ";

        if(!std::getline(std::cin, command))
        {
            std::cout<<"Error in reading the commands!"<<std::endl;
            break;
        }
        if (command.empty())
        {
            continue;
        }

        if (command == "help")
        {
            std::cout << "Available commands:\n"
                      << "  set\n"
                      << "  get\n"
                      << "  remove\n"
                      << "  exists\n"
                      << "  help\n"
                      << "  exit\n";
        }
        
        // std::cout <<"Enter the command (set/ get/ remove/ exists/ exit):";
        // std::getline(std::cin, command);

        if(command == "exit")
        {
            std::cout<<"Exiting the cacheforge!"<<std::endl;
            break;
        }
        else if(command == "set")
        {
            std::string key, value;
            std::cout<<"Enter the Key to set : ";
            std::getline(std::cin, key);
            std::cout<<"Enter the value to set : ";
            std::getline(std::cin, value);
            engine_.set(key,value);
            std::cout<<"Key-Value pair has been updated successfully!"<<std::endl; 
        }
        else if(command == "get")
        {
            std::string key;
            std::cout<<"Enter the key to get the value : ";
            std::getline(std::cin, key);
            auto value = engine_.get(key);
            if(value)
            {
                std::cout<<"Value for key '"<<key<<"' :"<<*value<<std::endl;
            }
            else
            {
                std::cout<<"Key '"<<key<<"' value pair not found!"<<std::endl;
            } 
        }
        else if(command == "remove")
        {
            std::string key;
            std::cout<<"Enter the key to remove : ";
            std::getline(std::cin, key);
            if(engine_.remove(key))
            {
                std::cout<<"Key '" <<key<<"' removed successfully!"<<std::endl;
            }
            else
            {
                std::cout<<"Key '" <<key<<"' not found in cache!"<<std::endl;
            }
        }
        else if(command == "exists")
        {
            std::string key;
            std::cout<<"Enter the key to check if it exists : ";
            std::getline(std::cin, key);
            if(engine_.exists(key))
            {
                std::cout<<"Key '"<<key<< "' exists in cache!"<<std::endl;
            }
            else
            {
                std::cout<<"Key '"<<key<< "' does not exist in cache!"<<std::endl;
            }
        }
        else
        {
            std::cout<<"Invalid command! Please enter a valid command (set/ get/ remove/ exists/ exit)"<<std::endl;
        }
    }
}