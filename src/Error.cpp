/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(const std::string &type, const std::string &message)
{
    this->_type = type;
    this->_message = message;
}

const char* Error::what(void) const noexcept
{
    return this->_message.c_str();
}

std::string const &Error::getType() const
{
    return this->_type;
}

Error::~Error()
{
}