#include <wtypes.h>
#include "gtest/gtest.h"
#include "samples/sample4.h"

bool ConditionMethod(bool param) {
    return param;
}

int BinaryMethod(int param) {
    return param;
}

TEST(sample_assert, BasicAssertions) {
    // condition是函数返回值
    EXPECT_TRUE(ConditionMethod(false));
    EXPECT_FALSE(ConditionMethod(true));

    // condition是表达式
    EXPECT_TRUE(1 == 0);
    EXPECT_FALSE(0 == 0);

    // condition是函数返回值+表达式
    Counter c;
    EXPECT_TRUE(0 != c.Increment());
    EXPECT_FALSE(1 == c.Increment());
}

HRESULT ComponentMethod(HRESULT param) {
    return param;
}

TEST(sample_assert, HRESULTAssertions) {
    // expression是数值
    EXPECT_HRESULT_SUCCEEDED(E_FAIL);
    EXPECT_HRESULT_FAILED(S_OK);

    // condition是函数返回值
    EXPECT_HRESULT_SUCCEEDED(ComponentMethod(E_FAIL));
    EXPECT_HRESULT_FAILED(ComponentMethod(S_OK));
}

TEST(sample_assert, BinaryComparison) {

    // EXPECT_EQ
    {
        int param = 10;
        Counter c;

        // 变量和函数返回值
        EXPECT_EQ(param, c.Increment());
        EXPECT_EQ(c.Increment(), param);

        // 数值和函数返回值
        EXPECT_EQ(100, BinaryMethod(param));
        EXPECT_EQ(BinaryMethod(param), 100);

        // 变量和数值
        EXPECT_EQ(param, 100);
        EXPECT_EQ(100, param);
    }

    // EXPECT_NE
    {
        int param = 0;
        Counter c;

        // 变量和函数返回值
        EXPECT_NE(param, c.Increment());
        ++param;
        EXPECT_NE(c.Increment(), param);

        // 数值和函数返回值
        param = 100;
        EXPECT_NE(100, BinaryMethod(param));
        EXPECT_NE(BinaryMethod(param), 100);

        // 变量和数值
        EXPECT_NE(param, 100);
        EXPECT_NE(100, param);
    }

    // EXPECT_LT
    {
        int param = 0;
        Counter c;

        // 变量和函数返回值
        EXPECT_LT(param, c.Increment());
        EXPECT_LT(c.Increment(), param);

        // 数值和函数返回值
        param = 100;
        EXPECT_LT(100, BinaryMethod(param));
        EXPECT_LT(BinaryMethod(param), 100);

        // 变量和数值
        EXPECT_LT(param, 100);
        EXPECT_LT(100, param);
    }

    // EXPECT_LE
    {
        int param = 0;
        Counter c;

        // 变量和函数返回值
        ++param;
        EXPECT_LE(param, c.Increment());
        param = 0;
        EXPECT_LE(c.Increment(), param);

        // 数值和函数返回值
        param = 10;
        EXPECT_LE(100, BinaryMethod(param));
        EXPECT_LE(BinaryMethod(param), 0);

        // 变量和数值
        EXPECT_LE(param, 0);
        EXPECT_LE(100, param);
    }

    // EXPECT_GT
    {
        int param = 0;
        Counter c;

        // 变量和函数返回值
        EXPECT_GT(c.Increment(), param);
        EXPECT_GT(param, c.Increment());

        // 数值和函数返回值
        param = 100;
        EXPECT_GT(100, BinaryMethod(param));
        EXPECT_GT(BinaryMethod(param), 100);

        // 变量和数值
        EXPECT_GT(param, 100);
        EXPECT_GT(100, param);
    }

    // EXPECT_GE
    {
        int param = 0;
        Counter c;

        // 变量和函数返回值
        ++param;
        EXPECT_GE(c.Increment(), param);
        param = 0;
        EXPECT_GE(param, c.Increment());

        // 数值和函数返回值
        param = 10;
        EXPECT_GE(0, BinaryMethod(param));
        EXPECT_GE(BinaryMethod(param), 100);

        // 变量和数值
        EXPECT_GE(param, 100);
        EXPECT_GE(0, param);
    }
}

TEST(sample_assert, StringComparison) {
}

