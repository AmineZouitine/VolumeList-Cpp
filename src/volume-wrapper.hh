#pragma once
#include <cstddef>

template<typename T>
class VolumeWrapper
{
public:
    VolumeWrapper(T& element, size_t min_position, size_t volume);

    T& get_element() const;
    size_t get_min_position() const;
    size_t get_max_position() const;
    size_t get_volume() const;

private:
    T& element_;
    size_t min_position_;
    size_t volume_;
    size_t max_position_;
};
#include "volume-wrapper.hxx"