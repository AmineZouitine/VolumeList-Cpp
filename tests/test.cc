#include <gtest/gtest.h>
#include <string>
#include "../src/volume-list.hh"

TEST(VolumeList, volume_list_init)
{
    auto list = VolumeList<std::string>{10, false};
    ASSERT_EQ(list.get_current_size(), 0);
    ASSERT_EQ(list.get_max_size(), 10);
    ASSERT_FALSE(list.get_is_dynamic_size());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}