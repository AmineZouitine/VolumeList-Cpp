#pragma once

#include <gtest/gtest.h>
#include <string>
#include "../src/volume-list.hh"

VolumeList<std::string> generator(size_t max_volume = 100, bool dynamic = false)
{
    return VolumeList<std::string>{max_volume, dynamic};
}