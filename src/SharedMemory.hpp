/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** SharedMemory
*/

#ifndef SHAREDMEMORY_HPP_
#define SHAREDMEMORY_HPP_
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

class SharedMemory {
    public:
        SharedMemory();
        ~SharedMemory();
        void sendMessage(std::string message);
        const char *receiveMessage() const;
    private:
        void *_shmem;
        size_t _maxLen;
};

#endif /* !SHAREDMEMORY_HPP_ */
