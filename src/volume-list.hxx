#include "volume-list.hh"

template <typename T>
VolumeList<T>::VolumeList(size_t max_volume, bool is_dynamic_size)
        : max_volume_(max_volume),
          current_volume_(0),
          element_number_(0),
          is_dynamic_size_(is_dynamic_size)
        {
        }

template <typename T>
inline size_t VolumeList<T>::get_max_volume() const
{
    return max_volume_;
}

template <typename T>
inline size_t VolumeList<T>::get_current_volume() const
{
    return current_volume_;
}

template <typename T>
inline size_t VolumeList<T>::get_element_number() const
{
    return element_number_;
}

template <typename T>
inline bool VolumeList<T>::get_is_dynamic_size()
{
    return is_dynamic_size_;
}


template<typename T>
void VolumeList<T>::append(const T&, size_t)
{
    //TODO
}

template<typename T>
inline T& VolumeList<T>::operator[](size_t)
{
    //TODO: i did that to compile hehe (temporary)
    auto e = new T();
    return *e;
}