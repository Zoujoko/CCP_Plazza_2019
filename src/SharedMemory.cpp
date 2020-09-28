/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** SharedMemory
*/

#include "SharedMemory.hpp"

// Creating shared memory with
SharedMemory::SharedMemory()
{
    int protection = PROT_READ | PROT_WRITE;
    int visibility = MAP_ANONYMOUS | MAP_SHARED;

    this->_maxLen = 128;
    this->_shmem = mmap(NULL, 128, protection, visibility, 0, 0);
}

// Sent message to shared memory
void SharedMemory::sendMessage(std::string message)
{
    const char *toSend = std::string(message).c_str();

    memcpy(this->_shmem, toSend, strlen(toSend));
}
// Just a print to show it's working  but basically the received message is
// already stocked in _shmem
const char *SharedMemory::receiveMessage() const
{
    char *str = (char *)this->_shmem;

    return str;
}

SharedMemory::~SharedMemory()
{
}