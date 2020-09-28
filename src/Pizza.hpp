/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include "Enum.hpp"
#include <regex>

class Pizza {
    public:
        Pizza(order_t order, float multi);
        Pizza(std::string data);
        PizzaType getType() const;
        float getBakingTime() const;
        std::string serializeData();
        PizzaSize getSize() const;
        ~Pizza();

    protected:
    private:
        PizzaType _type;
        PizzaSize _size;
        float _bakingTime;
};

std::ostream &operator<<(std::ostream &s, const Pizza &pizza);

#endif /* !PIZZA_HPP_ */
