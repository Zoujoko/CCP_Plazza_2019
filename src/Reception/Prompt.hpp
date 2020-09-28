/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Prompt
*/

#ifndef PROMPT_HPP_
#define PROMPT_HPP_
#include <string>
#include <iostream>
#include <regex>
#include <algorithm>
#include <cctype>
#include "../Enum.hpp"
#include "Reception.hpp"

class Prompt {
    public:
        Prompt();
        std::vector<order_t> getInput();
        static std::string gettingPizzaName(PizzaType type);
        static std::string gettingPizzaSize(PizzaSize size);
        PizzaType getType() const;
        PizzaSize getSize() const;
        int getAmount() const;
        void parsingInput(std::string line);
        ~Prompt();

    protected:
    private:
        void addingOrderToVector();
        void setPizza(std::string line);
        void setAmount(std::string line);
        void setSize(std::string line);
        PizzaType _pizzaType;
        PizzaSize _pizzaSize;
        int _amount;
        std::string _input;
        std::vector<order_t> _orders;
};


typedef struct pizza_name_s
{
    PizzaType type;
    std::string name;
}               pizza_name_t;

typedef struct pizza_size_s
{
    PizzaSize size;
    std::string name;
}               pizza_size_t;


#endif /* !PROMPT_HPP_ */
