/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_
#include <string>
#include <iostream>
#include "Prompt.hpp"
#include <fstream>
#include "../Pizza.hpp"
#include "../Kitchen.hpp"
#include "../Enum.hpp"
#include "../Process.hpp"
#include "../SharedMemory.hpp"
#define LOGFILE "receptionLog"

class Reception {
    public:
        Reception();
        Reception(std::string multi, std::string cooks, std::string time);
        void loop();
        void givingPizza();
        void gettingOrder();
        bool goodOrder();
        void statusCommand();
        bool addingToLog();
        void creatingKitchens();
        float getMulti() const;
        int getCooks() const;
        int getRestockTime() const;
        bool getGood() const;
        ~Reception();

    protected:
    private:
        std::vector<order_t> _orders;
        float _multi;
        int _maxCooks;
        int _restock;
        bool _good;
        std::vector <SharedMemory > _ipcs;
};

#endif /* !RECEPTION_HPP_ */
