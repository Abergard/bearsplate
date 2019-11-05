#include <gtest/gtest.h>

#include "bearsplate.hpp"

TEST(RunApplicationTest, emptyRunApplicationFunction_returnsAlwaysZero)
{
    const auto [result, value] = run_application();

    EXPECT_EQ(0, result);
    EXPECT_EQ(12, value);
}
