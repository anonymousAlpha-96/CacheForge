#include "cacheforge/CacheEngine.h"
#include <iostream>

int main()
{
    std::cout<<"Welcome to cacheforge!"<<std::endl;
    std::cout<<"In-Memory key-value database is starting..."<<std::endl;

    CacheEngine engine;

    engine.set("name", "Ankit");
    auto value = engine.get("name");

    if(value)
    {
        std::cout<<"Value for key 'name':"<<*value<<std::endl;
    }
    else
    {
        std::cout<<"key value pair not found!"<<std::endl;
    }
    auto ageValue = engine.get("age");

    if(ageValue)
    {
        std::cout<<"Value for key 'age':"<<*ageValue<<std::endl;
    }
    else
    {
        std::cout<<"key value pair not found!"<<std::endl;
    }

    if(engine.exists("name"))
    {
        std::cout<<"key 'name' exists in cache!"<<std::endl;
    }
    else
    {
        std::cout<<"key 'name' does not exist in cache!"<<std::endl;
    }

    if(engine.remove("name"))
    {
        std::cout<<"key 'name' removed from cache!"<<std::endl;
    }
    else
    {
        std::cout<<"key 'name' not found in cache!"<<std::endl;
    }

    if(engine.exists("name"))
    {
        std::cout<<"key 'name' exists in cache!"<<std::endl;
    }
    else
    {
        std::cout<<"key 'name' does not exist in cache!"<<std::endl;
    }

    return 0;
}