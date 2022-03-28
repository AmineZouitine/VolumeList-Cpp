#pragma once

#include <cstddef>
#include <iostream>
#include "volume-wrapper.hh"
#include <vector>

template<typename T>
class VolumeList
{

public:
    VolumeList(size_t max_volume, bool is_dynamic_size = false);
    ~VolumeList() = default;

    void append(T& element, size_t volume);

    T& operator[](size_t index);
    
    // Only for testing purpose (deleted in release)
    VolumeWrapper<T>& get_wrapper_at_index(size_t index);

    size_t get_max_volume() const;
    size_t get_current_volume() const;
    size_t get_element_number() const;
    size_t get_remaining_volume() const;
    bool get_is_dynamic_size();

private:
    size_t max_volume_;
    size_t current_volume_;
    bool is_dynamic_size_;
    size_t remaining_volume_;

    std::vector<VolumeWrapper<T>> elements_;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const VolumeList<T>& volume_list);

#include "volume-list.hxx"