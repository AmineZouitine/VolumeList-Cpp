#pragma once

#include <cstddef>
#include <iostream>

template<typename T>
class VolumeList
{

public:
    VolumeList(size_t max_size, bool is_dynamic_size = false);
    ~VolumeList() = default;

    void append(const T& element);

    inline size_t get_max_size() const
    {
        return max_size_;
    }

    inline size_t get_current_size() const
    {
        return current_size_;
    }

    inline bool get_is_dynamic_size()
    {
        return is_dynamic_size_;
    }
private:
    size_t max_size_;
    size_t current_size_;
    bool is_dynamic_size_;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const VolumeList<T>& volume_list);

#include "volume-list.hxx"