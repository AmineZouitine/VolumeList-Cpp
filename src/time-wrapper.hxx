#include "time-wrapper.hh"
 
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
    return min_position_ + duration_;
}

template<typename T>
inline size_t TimeWrapper<T>::get_duration() const
{
    return duration_;
}

