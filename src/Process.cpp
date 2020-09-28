/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Process
*/

#include "Process.hpp"

Process::Process(SharedMemory &mems, float multiplier, int maxCooks, int restock)
{
    this->_mems = mems;
    this->_multiplier = multiplier;
    this->_maxCooks = maxCooks;
    this->_restockTime = restock;
    std::cout << "New kitchen " << std::endl;
}

pid_t Process::getProcessPid() const
{
    return getpid();
}

void Process::mainLoop()
{
    Kitchen kitchen(this->_multiplier, this->_maxCooks, this->_restockTime);

    while (kitchen.getStatus(this->_mems)) {
        if (kitchen.getCommand().compare(0, 6, "status") == 0) {
            kitchen.printStatus();
            this->_mems.sendMessage("Ok");
        }
        else if (kitchen.getCommand().compare(0, 4, "None") != 0) {
            if (kitchen.addingCommand()) {
                this->_mems.sendMessage("Ok");
                usleep(50);
            }
            else {
                this->_mems.sendMessage("Error");
                usleep(50);
            }
        }
    }
    this->_mems.sendMessage("Destroy");
    std::cout << "Kitchen Destroyed" << std::endl;
}

Process::~Process()
{
}
