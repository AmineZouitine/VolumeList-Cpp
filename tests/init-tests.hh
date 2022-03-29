#pragma once

#include <gtest/gtest.h>
#include <string>
#include "../src/volume-list.hh"
#include "utils_tests.hh"

TEST(init, volume_list_init)
{
    auto list = generator();
    ASSERT_EQ(list.get_max_volume(), 100);
    ASSERT_EQ(list.get_current_volume(), 0);
    ASSERT_EQ(list.get_element_number(), 0);
    ASSERT_FALSE(list.get_is_dynamic_size());
}