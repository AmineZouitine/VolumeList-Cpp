#include "volume-list.hh"
#include "maximum-volume.hh"

template <typename T>
VolumeList<T>::VolumeList(size_t max_volume, bool is_dynamic_size)
        : max_volume_(max_volume),
          current_volume_(0),
          is_dynamic_size_(is_dynamic_size),
          remaining_volume_(max_volume_)
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
inline size_t VolumeList<T>::get_remaining_volume() const
{
    return max_volume_ - current_volume_;
}

template <typename T>
inline size_t VolumeList<T>::get_element_number() const
{
    return elements_.size();
}

template <typename T>
inline bool VolumeList<T>::get_is_dynamic_size()
{
    return is_dynamic_size_;
}

template<typename T>
inline void VolumeList<T>::append(T& element, size_t volume)
{
    if (current_volume_ + volume > max_volume_)
        throw MaximumVolume("You trying to add a volume of " + std::to_string(volume)
            + "but only " + std::to_string(remaining_volume_)+ " is remaining.");

    auto last_min_position = get_element_number() > 0
        ? elements_.back().get_max_position() : 0; 

    elements_.push_back(TimeWrapper<T>(element, last_min_position, volume));
    current_volume_ += volume;
}

template<typename T>
inline T& VolumeList<T>::operator[](size_t index)
{
    if (index >= get_element_number())
        throw std::out_of_range("you try to access the index: "+ std::to_string(index)+
            " when the interval is [0, "+ std::to_string(get_element_number()) + "]");
    return elements_[index].get_element();
}