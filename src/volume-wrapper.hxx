#include "volume-wrapper.hh"
 

template<typename T>
VolumeWrapper<T>::VolumeWrapper(T& element, size_t min_position, size_t volume)
    : element_(element),
      min_position_(min_position),
      volume_(volume)
{
}

template<typename T>
inline T& VolumeWrapper<T>::get_element() const
{
    return element_;
}

template<typename T>
inline size_t VolumeWrapper<T>::get_min_position() const
{
    return min_position_;
}

template<typename T>
inline size_t VolumeWrapper<T>::get_max_position() const
{
    return min_position_ + volume_;
}

template<typename T>
inline size_t VolumeWrapper<T>::get_volume() const
{
    return volume_;
}

template<typename T>
bool VolumeWrapper<T>::operator==(const VolumeWrapper<T>& rhs)
{
    return min_position_ == rhs.get_min_position();
}

template<typename T>
void VolumeWrapper<T>::set_min_position(size_t new_min_position)
{
   min_position_ = new_min_position;
}
