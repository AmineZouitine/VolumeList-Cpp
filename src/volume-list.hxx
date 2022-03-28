#include "volume-list.hh"

template <typename T>
VolumeList<T>::VolumeList(size_t max_size, bool is_dynamic_size)
        : max_size_(max_size), current_size_(0), is_dynamic_size_(is_dynamic_size)
        {
        }

