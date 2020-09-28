/*
** EPITECH PROJECT, 2020
** Bootstrap Plazza
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
#define MUTEX_HPP_
#include "IMutex.hpp"
#include <pthread.h>
#include <mutex>

class Mutex : public virtual IMutex {
    public:
        Mutex();
        virtual void lock() override;
        virtual void unlock() override;
        virtual void trylock() override;
        ~Mutex();

    protected:
    private:
        pthread_mutex_t _mtx;
};

#endif /* !MUTEX_HPP_ */
