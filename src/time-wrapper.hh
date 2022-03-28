#pragma once
#include <cstddef>

template<typename T>
class TimeWrapper
{
    TimeWrapper(T& element, size_t min_position, size_t duration);

    T& get_element() const;
    size_t get_min_position() const;
    size_t get_max_position() const;
    size_t get_duration() const;

private:
    T& element_;
    size_t min_position_;
    size_t duration_;
    size_t max_position_;
};
#include "time-wrapper.hxx"