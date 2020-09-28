/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_
#include <string>
#include <iostream>

class Error : public std::exception {
    public:
        Error(const std::string &type, const std::string &message);
        ~Error();
        const char *what() const noexcept;
        std::string const &getType() const;

    protected:
    private:
        std::string _message;
        std::string _type;
};

#endif /* !ERROR_HPP_ */
