// Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
// Author: Ge,Jun (gejun@baidu.com)

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <gtest/gtest.h>
#include "base/time.h"
#include "base/macros.h"

namespace {

class CachelineTest : public testing::Test {
};

struct BAIDU_CACHELINE_ALIGNMENT Bar {
    int y;
};

struct Foo {
    char dummy1[0];
    int z;
    int BAIDU_CACHELINE_ALIGNMENT x[0];
    int y;
    int m;
    Bar bar;
};

TEST_F(CachelineTest, cacheline_alignment) {
    ASSERT_EQ(64u, offsetof(Foo, x));
    ASSERT_EQ(64u, offsetof(Foo, y));
    ASSERT_EQ(68u, offsetof(Foo, m));
    ASSERT_EQ(128u, offsetof(Foo, bar));
    ASSERT_EQ(64u, sizeof(Bar));
    ASSERT_EQ(192u, sizeof(Foo));
}

}