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
    auto elem = std::string("Boring guy");

    list.append(elem, 10);
    
    ASSERT_EQ(list.get_current_volume(), 10);
    ASSERT_EQ(list.get_element_number(), 1);
    ASSERT_EQ(list[0], "Boring guy");

    auto wrapper = list.get_wrapper_at_index(0);
    ASSERT_EQ(wrapper.get_max_position(), 10);
    ASSERT_EQ(wrapper.get_min_position(), 0);
    ASSERT_EQ(wrapper.get_volume(), 10);
}

TEST(VolumeList, multiple_add)
{
    auto list = generator();
    auto elem = std::string("Boring guy");
    auto elem2 = std::string("PyBrook");

    list.append(elem, 10);
    list.append(elem2, 5);
    
    ASSERT_EQ(list.get_current_volume(), 15);
    ASSERT_EQ(list.get_element_number(), 2);
    ASSERT_EQ(list[0], "Boring guy");
    ASSERT_EQ(list[1], "PyBrook");

    auto wrapper = list.get_wrapper_at_index(0);
    ASSERT_EQ(wrapper.get_max_position(), 10);
    ASSERT_EQ(wrapper.get_min_position(), 0);
    ASSERT_EQ(wrapper.get_volume(), 10);

    auto wrapper2 = list.get_wrapper_at_index(1);
    ASSERT_EQ(wrapper2.get_max_position(), 15);
    ASSERT_EQ(wrapper2.get_min_position(), 10);
    ASSERT_EQ(wrapper2.get_volume(), 5);

}



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