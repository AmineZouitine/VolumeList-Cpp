#pragma once

#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "../src/volume-list.hh"
#include "utils_tests.hh"


TEST(cout, cout_empty)
{
    auto list = generator();
    ::testing::internal::CaptureStdout();
    std::cout << list;
    auto out = ::testing::internal::GetCapturedStdout();

    ASSERT_EQ(out, "");
}

TEST(cout, cout_multiple)
{
    auto list = generator();
    auto elem = std::string("Boring guy");
    auto elem1 = std::string("PyBrook");
    auto elem2 = std::string("RL_Shooter");
    list.append(elem, 10);
    list.append(elem1, 10);
    list.append(elem2, 10);

    ::testing::internal::CaptureStdout();
    std::cout << list;
    auto out = ::testing::internal::GetCapturedStdout();

    ASSERT_EQ(out,
              "-------[0]-------\n"
              "Element: Boring guy\n"
              "Position: [0, 10]\n"
              "Volume: 10\n"
              "-------[1]-------\n"
              "Element: PyBrook\n"
              "Position: [10, 20]\n"
              "Volume: 10\n"
              "-------[2]-------\n"
              "Element: RL_Shooter\n"
              "Position: [20, 30]\n"
              "Volume: 10\n");
}