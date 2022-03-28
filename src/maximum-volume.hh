#pragma once

#include <exception>
#include <string>

class MaximumVolume : public std::exception
{
public:
    MaximumVolume(const std::string& msg);
    virtual const char* what() const noexcept;

private:
    const std::string msg_;
};