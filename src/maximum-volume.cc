#include "maximum-volume.hh"

MaximumVolume::MaximumVolume(const std::string &msg)
    : msg_(msg)
{}

const char* MaximumVolume::what() const noexcept
{
    return msg_.c_str();
}