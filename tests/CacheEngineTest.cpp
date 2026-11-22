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