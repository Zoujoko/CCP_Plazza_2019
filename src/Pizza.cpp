/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Pizza
*/

#include "Pizza.hpp"

const float bakingTimes[] {
    0,
    2,
    1,
    0,
    2,
    0,0,0,
    4,
};

Pizza::Pizza(order_t order, float multi)
{
    this->_type = order.pizza;
    this->_size = order.size;
    this->_bakingTime = bakingTimes[order.pizza] * multi;
}

Pizza::Pizza(std::string data)
{
    std::regex regexr("([0-9]|[.])+");
    auto ite = std::sregex_iterator(data.begin(), data.end(), regexr);
    auto end = std::sregex_iterator();
    int count = 0;

    for (auto i = ite; i != end; i++) {
        std::smatch match = *i;
        if (count == 0)
            this->_type = (PizzaType)std::stoi(match.str());
        else if (count == 1)
            this->_size = (PizzaSize)std::stoi(match.str());
        else
            this->_bakingTime = std::stof(match.str());
        count++;
    }
}

// Getters
PizzaType Pizza::getType() const
{
    return (this->_type);
}

PizzaSize Pizza::getSize() const
{
    return (this->_size);
}

float Pizza::getBakingTime() const
{
    return this->_bakingTime;
}

std::string Pizza::serializeData()
{
    std::string ret = std::string(std::to_string(this->_type)) + "|" + std::string(std::to_string(this->_size)) + "|" + std::string(std::to_string(this->_bakingTime));
    return ret;
}

Pizza::~Pizza()
{
}

// Overload << to print all infos about pizza
std::ostream &operator<<(std::ostream &s, const Pizza &pizza)
{
    std::cout << "Pizza " << pizza.getType() << " of size " << pizza.getSize() << std::endl;
    return (s);
}