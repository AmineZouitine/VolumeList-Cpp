#include "volume-list.hh"
#include "maximum-volume.hh"


template <typename T>
VolumeList<T>::VolumeList(size_t max_volume, bool is_dynamic_size)
        : max_volume_(max_volume),
          current_volume_(0),
          is_dynamic_size_(is_dynamic_size),
          remaining_volume_(max_volume_)
{}

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
inline bool VolumeList<T>::get_is_dynamic_size() const
{
    return is_dynamic_size_;
}

template <typename T>
inline void VolumeList<T>::check_resize(size_t volume)
{
    if (current_volume_ + volume > max_volume_)
    {
        if (is_dynamic_size_)
            max_volume_ += volume + (max_volume_ * 2);
        else
            throw MaximumVolume("You trying to add a volume of " + std::to_string(volume) + 
                " but only " + std::to_string(get_remaining_volume()) + " is remaining.");
    }


}

template <typename T>
inline void VolumeList<T>::check_out_of_range(size_t min_position)
{
    if (min_position > get_max_volume())
    {
        if (is_dynamic_size_)
            max_volume_ += min_position;
        else
            throw std::out_of_range("You trying to add a elem with a min position of "
                + std::to_string(min_position) + 
                " but only [0, " + std::to_string(get_max_volume()) + "] is posible.");

    }
}

template <typename T>
void VolumeList<T>::check_negative_volume(size_t volume)
{
    if (volume < 0)
        throw std::invalid_argument("Negative volume is invalid");
}

template<typename T>
inline void VolumeList<T>::append(T& element, size_t volume)
{
    check_negative_volume(volume);
    check_resize(volume);

    auto last_min_position = get_element_number() > 0
        ? elements_.back().get_max_position() : 0; 

    elements_.push_back(VolumeWrapper<T>(std::make_shared<T>(element), last_min_position, volume));
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

template<typename T>
inline VolumeWrapper<T>& VolumeList<T>::get_volume_at(size_t index)
{
    if (index >= get_element_number())
        throw std::out_of_range("you try to access the index: " + std::to_string(index) +
                                " when the interval is [0, " + std::to_string(elements_.size() == 0 ? 0 : elements_.size() - 1) + "]");
    return elements_[index];
}

template<typename T>
inline void VolumeList<T>::elements_shift(VolumeWrapper<T>& element)
{
    elements_.push_back(element);
    for (size_t i = 0; i < elements_.size() - 1; i++)
    {
        if (elements_[i].is_overlaping(element))
        {
            elements_[i].set_min_position(element.get_max_position());
            element = elements_[i];
        }
    }
    std::sort(begin(), end());
    // std::sort(elements_.begin(), elements_.end());
}

template<typename T>
inline void VolumeList<T>::insert(T& element, size_t min_position, size_t volume)
{
    check_negative_volume(volume);
    check_out_of_range(min_position);
    check_resize(volume);

    auto new_elem = VolumeWrapper<T>(std::make_shared<T>(element), min_position, volume);
    elements_shift(new_elem);
    current_volume_ += volume;
}

template<typename T>
void VolumeList<T>::remove(size_t index)
{
    if (index >= elements_.size())
        throw std::out_of_range("Your index: " + std::to_string(index)
            + " but interval is [0, " + 
            std::to_string(elements_.size() == 0 ? 0 : elements_.size() - 1) + "].");


    current_volume_ -= elements_[index].get_volume();
    elements_.erase(elements_.begin() + index);
}

template<typename T>
std::vector<VolumeWrapper<T>>::const_iterator VolumeList<T>::begin() const
{
    return elements_.cbegin();
}

template<typename T>
std::vector<VolumeWrapper<T>>::iterator VolumeList<T>::begin()
{
    return elements_.begin();
}


template<typename T>
inline std::vector<VolumeWrapper<T>>::const_iterator VolumeList<T>::end() const
{
    return elements_.cend();
}

template<typename T>
inline std::vector<VolumeWrapper<T>>::iterator VolumeList<T>::end()
{
    return elements_.end();
}

template<typename T>
std::ostream& operator<<(std::ostream& os, VolumeList<T>& volume_list)
{
    for (size_t i = 0; i < volume_list.get_element_number(); i++)
    {
        os << "-------[" << i << "]-------\n";
        os << volume_list.get_volume_at(i);
    }
    return os;
}
