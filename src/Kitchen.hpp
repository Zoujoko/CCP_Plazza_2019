/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <iostream>
#include <map>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <vector>
#include <chrono>
#include <thread>
#include <ctime>
#include "Cook.hpp"
#include "Enum.hpp"
#include "Mutex.hpp"
#include "Pizza.hpp"
#include "SharedMemory.hpp"

class Kitchen {
    public:
        Kitchen(int cookingTime, int nbCooks, int restockTime);
        ~Kitchen();

        void restockIngredients();
        bool checkNbCommands();
        void isKitchenActive();
        void printStatus();
        void joinCooks();
        void startCooks();
        bool cooksActive();
        bool getStatus(SharedMemory mems);
        bool addingCommand();
        void checkingCooks();
        bool removingIngredients();
        pid_t getPid();
        size_t getCookingTime() const;
        size_t getRestockTime() const;
        size_t getCooksNb() const;
        std::string getCommand() const;

    protected:
    private:
        size_t _cookingTime;
        size_t _restockTime;
        size_t _nbCooks;
        size_t _commands = 0;
        bool _isActive;
        std::string _command;
        std::map<Ingredient, int> _stocks;
        std::vector<Cook *> _pool;
        std::vector<Pizza> _queue;
        Mutex _mtx;
};

void *prepareCommand(void *time);
#endif /* !KITCHEN_HPP_ */
