#pragma once

#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "utils_tests.hh"
#include "../src/volume-list.hh"

TEST(insert, simple_insert)
{
    auto list = generator();
    auto elem = std::string("Boring guy");
    
    list.insert(elem, 0, 10);

    ASSERT_EQ(list.get_current_volume(), 10);
    ASSERT_EQ(list.get_element_number(), 1);
    ASSERT_EQ(list[0], "Boring guy");

    auto wrapper = list.get_volume_at(0);
    ASSERT_EQ(wrapper.get_max_position(), 9);
    ASSERT_EQ(wrapper.get_min_position(), 0);
    ASSERT_EQ(wrapper.get_volume(), 10);
}

TEST(insert, multiple_insert_no_overlaping)
{
    auto list = generator();
    
    auto elem = std::string("Boring guy");
    auto elem2 = std::string("PyBrook");

    list.insert(elem, 0, 10);
    list.insert(elem2, 9, 5);
    
    ASSERT_EQ(list.get_current_volume(), 15);
    ASSERT_EQ(list.get_element_number(), 2);
    ASSERT_EQ(list[0], "Boring guy");
    ASSERT_EQ(list[1], "PyBrook");

    auto wrapper = list.get_volume_at(0);
    ASSERT_EQ(wrapper.get_max_position(), 9);
    ASSERT_EQ(wrapper.get_min_position(), 0);
    ASSERT_EQ(wrapper.get_volume(), 10);

    auto wrapper2 = list.get_volume_at(1);
    ASSERT_EQ(wrapper2.get_max_position(), 14);
    ASSERT_EQ(wrapper2.get_min_position(), 9);
    ASSERT_EQ(wrapper2.get_volume(), 5);
}

TEST(insert, multiple_insert_overlaping)
{
    auto list = generator();
    
    auto elem = std::string("Boring guy");
    auto elem2 = std::string("PyBrook");

    list.insert(elem, 0, 10);
    list.insert(elem2, 2, 5);
    
    ASSERT_EQ(list.get_current_volume(), 15);
    ASSERT_EQ(list.get_element_number(), 2);
    ASSERT_EQ(list[0], "PyBrook");
    ASSERT_EQ(list[1], "Boring guy");
    
    auto wrapper = list.get_volume_at(0);
    ASSERT_EQ(wrapper.get_min_position(), 2);
    ASSERT_EQ(wrapper.get_max_position(), 7);
    ASSERT_EQ(wrapper.get_volume(), 5);

    auto wrapper2 = list.get_volume_at(1);
    ASSERT_EQ(wrapper2.get_min_position(), 7);
    ASSERT_EQ(wrapper2.get_max_position(), 17);
    ASSERT_EQ(wrapper2.get_volume(), 10);
}


TEST(insert, multiple_insert_overlaping_hard)
{
    auto list = generator();
    
    auto elem = std::string("Boring guy");
    auto elem2 = std::string("PyBrook");
    auto elem3 = std::string("Adil");
    auto elem4 = std::string("Mehdi");

    list.insert(elem, 0, 50);
    list.insert(elem2, 2, 7);
    list.insert(elem3, 2, 9);
    list.insert(elem4, 0, 5);


    auto wrapper = list.get_volume_at(0);
    ASSERT_EQ(wrapper.get_max_position(), 4);
    ASSERT_EQ(wrapper.get_min_position(), 0);
    ASSERT_EQ(wrapper.get_volume(), 5);

    auto wrapper2 = list.get_volume_at(1);
    ASSERT_EQ(wrapper2.get_max_position(), 13);
    ASSERT_EQ(wrapper2.get_min_position(), 4);
    ASSERT_EQ(wrapper2.get_volume(), 9);

    auto wrapper3 = list.get_volume_at(2);
    ASSERT_EQ(wrapper3.get_max_position(), 20);
    ASSERT_EQ(wrapper3.get_min_position(), 13);
    ASSERT_EQ(wrapper3.get_volume(), 7);

    auto wrapper4 = list.get_volume_at(3);
    ASSERT_EQ(wrapper4.get_max_position(), 70);
    ASSERT_EQ(wrapper4.get_min_position(), 20);
    ASSERT_EQ(wrapper4.get_volume(), 50);
}


TEST(append, insert_out_of_range_NOT_dynamic)
{
    auto list = generator(0);
    auto elem = std::string("Boring guy");
    try
    {
        list.insert(elem, 0, 10);
        // line above should throw an exeption, so this line should never be executed
        ASSERT_TRUE(false); 
    }
    catch(const MaximumVolume& exp)
    {
        ASSERT_STREQ("You trying to add a volume of 10 but only 0 is remaining.",
            exp.what());
    }
}


TEST(append, insert_out_of_range_dynamic)
{
    auto list = generator(0, true);
    auto elem = std::string("Boring guy");
    list.insert(elem, 0, 10);

    ASSERT_EQ(list.get_current_volume(), 10);
    ASSERT_EQ(list.get_element_number(), 1);
    ASSERT_EQ(list[0], "Boring guy");

    auto wrapper = list.get_volume_at(0);
    ASSERT_EQ(wrapper.get_max_position(), 9);
    ASSERT_EQ(wrapper.get_min_position(), 0);
    ASSERT_EQ(wrapper.get_volume(), 10);
}