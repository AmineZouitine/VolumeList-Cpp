#include <gtest/gtest.h>
#include <string>
#include "../src/volume-list.hh"


static VolumeList<std::string> generator(size_t max_volume = 100, bool dynamic = false)
{
    return VolumeList<std::string>{max_volume, dynamic};
}
TEST(VolumeList, volume_list_init)
{
    auto list = generator();
    ASSERT_EQ(list.get_max_volume(), 100);
    ASSERT_EQ(list.get_current_volume(), 0);
    ASSERT_EQ(list.get_element_number(), 0);
    ASSERT_FALSE(list.get_is_dynamic_size());
}

TEST(VolumeList, simple_add)
{
    auto list = generator();

    list.append(std::string("Boring guy"), 10);
    
    ASSERT_EQ(list.get_current_volume(), 10);
    ASSERT_EQ(list.get_element_number(), 1);
    ASSERT_EQ(list[0], "Boring guy");
}

// TEST(VolumeList, multiple_add)
// {
    
// }


// TEST(VolumeList, add_out_of_range_NOT_dynamic)
// {
    
// }


// TEST(VolumeList, add_out_of_range_dynamic)
// {
    
// }

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}