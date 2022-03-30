#pragma once

#include <cstddef>
#include <iostream>
#include <vector>

#include "volume-wrapper.hh"

template<typename T>
class VolumeList
{
public:

    VolumeList(size_t max_volume, bool is_dynamic_size = false);
    ~VolumeList() = default;

    void append(T& element, size_t volume);
    void insert(T& element, size_t min_position, size_t volume);
    void remove(size_t index);

    T& operator[](size_t index);
    VolumeWrapper<T>& get_volume_at(size_t index);

    size_t get_max_volume() const;
    size_t get_current_volume() const;
    size_t get_element_number() const;
    size_t get_remaining_volume() const;
    bool get_is_dynamic_size();


    std::vector<VolumeWrapper<T>>::const_iterator begin() const;
    std::vector<VolumeWrapper<T>>::iterator begin();
    std::vector<VolumeWrapper<T>>::const_iterator end() const;
    std::vector<VolumeWrapper<T>>::iterator end();


private:
    void sort();
    void elements_shift(VolumeWrapper<T>& element);
    void check_resize(size_t volume);
    void check_out_of_range(size_t min_position);

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