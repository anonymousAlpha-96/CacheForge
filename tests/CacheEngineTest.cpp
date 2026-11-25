
/*##########################################################################################################
#copyright (c) 2026 reserved
#Author: Ankit
#Date: 2026/24/11
#Description: CacheEngineTest.cpp for CacheForge project
##########################################################################################################*/

//=========================================================================================================
// 21-Nov-26 : Task 01 : initial commits 
//=========================================================================================================
// 25-Nov-26 : Task 02 - New test case added for copy constructor to check the copying the objects.
//=========================================================================================================

#include <gtest/gtest.h>
#include "cacheforge/CacheEngine.h"

TEST (CacheEngineTest, StoreAndRetrieveValue)
{
    CacheEngine engine;

    engine.set("city", "Pune");
    auto result = engine.get("city");

    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), "Pune");
}

TEST (CacheEngineTest, CopyCacheEngine)
{
    CacheEngine CopyCacheA;

    CopyCacheA.set("name", "Virat");
    CopyCacheA.set("city", "Bangalore");

    CacheEngine CopyCacheB = CopyCacheA; 

    CopyCacheB.set("name", "Kohli");

    EXPECT_EQ(CopyCacheA.get("name").value(), "Virat");

    EXPECT_EQ(CopyCacheB.get("name").value(), "Kohli");

    EXPECT_EQ(CopyCacheA.get("city").value(), "Bangalore");
    EXPECT_EQ(CopyCacheB.get("city").value(), "Bangalore");
}