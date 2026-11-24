
/*##########################################################################################################
#copyright (c) 2026 reserved
#Author: Ankit
#Date: 2026/24/11
#Description: CacheEngineTest.cpp for CacheForge project
##########################################################################################################*/

//=========================================================================================================
// 21-Nov-26 : Task 01 : initial commits 
//=========================================================================================================

#include <gtest/gtest.h>
#include "cacheforge/CacheEngine.h"

TEST (CacheEngineTest, StoreAndRetrieveValue)
{
    CacheEngine engine;

    engine.set("name", "Ankit");
    auto result = engine.get("name");

    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), "Ankit");
}