/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** enum
*/

#ifndef ENUM_HPP_
#define ENUM_HPP_
#include "Error.hpp"

enum PizzaType
{
    NoneType = 0,
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8,
};

enum PizzaSize
{
    NoneSize = 0,
    S = 1,
    M = 2,
    L = 4,
    XL = 6,
    XXL = 8,
};

enum Ingredient
{
    NoneIngredient = 0,
    Dough = 1,
    TomatoSauce = 2,
    Gruyere = 3,
    Ham = 4,
    Mushroom = 5,
    Steak = 6,
    Eggplant = 7,
    GoatCheese = 8,
    ChiefLove = 9,
};

typedef struct order_s {
    PizzaType pizza;
    PizzaSize size;
    int amount;
    std::string input;
}               order_t;

#endif /* !ENUM_HPP_ */
