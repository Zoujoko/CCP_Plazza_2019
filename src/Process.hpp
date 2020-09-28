/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Process
*/

#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include "SharedMemory.hpp"
#include "Kitchen.hpp"
class Process {
    public:
        Process(SharedMemory &mems, float multiplier, int maxCooks, int restock);
        pid_t getProcessPid() const;
        void mainLoop();
        ~Process();

    protected:
    private:
        SharedMemory _mems;
        float _multiplier;
        int _maxCooks;
        int _restockTime;

};

#endif /* !PROCESS_HPP_ */
