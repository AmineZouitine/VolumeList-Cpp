#pragma once

#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "utils_tests.hh"
#include "../src/volume-list.hh"

TEST(remove, remove_elem)
{
    auto list = generator();
    auto elem = std::string("Bye you :c");
    
    list.append(elem, 10);
    list.remove(0);
    ASSERT_EQ(list.get_current_volume(), 0);
    ASSERT_EQ(list.get_element_number(), 0);
}


TEST(remove, remove_error)
{
    auto list = generator(0);
    auto elem = std::string("Boring guy");
    try
    {
        list.remove(0);
        // line above should throw an exeption, so this line should never be executed
        ASSERT_TRUE(false); 
    }
    catch(const std::out_of_range& exp)
    {
        ASSERT_STREQ("Your index: 0 but interval is [0, 0].",
            exp.what());
    }
}