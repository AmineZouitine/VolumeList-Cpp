#pragma once

#include <gtest/gtest.h>
#include <string>
#include "../src/volume-list.hh"
#include "utils_tests.hh"

TEST(insert, simple_insert)
{
    auto list = generator();
    auto elem = std::string("Boring guy");
    
    list.insert(elem, 0, 10);

    ASSERT_EQ(list.get_current_volume(), 10);
    ASSERT_EQ(list.get_element_number(), 1);
    ASSERT_EQ(list[0], "Boring guy");

    auto wrapper = list.get_volume_at(0);
    ASSERT_EQ(wrapper.get_max_position(), 10);
    ASSERT_EQ(wrapper.get_min_position(), 0);
    ASSERT_EQ(wrapper.get_volume(), 10);
}