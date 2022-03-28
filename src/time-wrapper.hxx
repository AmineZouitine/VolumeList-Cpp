#include "time-wrapper.hh"
 

template<typename T>
TimeWrapper<T>::TimeWrapper(T& element, size_t min_position, size_t volume)
    : element_(element),
      min_position_(min_position),
      volume_(volume)
{
}

template<typename T>
inline T& TimeWrapper<T>::get_element() const
{
    return element_;
}

template<typename T>
inline size_t TimeWrapper<T>::get_min_position() const
{
    return min_position_;
}

template<typename T>
inline size_t TimeWrapper<T>::get_max_position() const
{
    return min_position_ + volume_;
}

template<typename T>
inline size_t TimeWrapper<T>::get_volume() const
{
    return volume_;
}
