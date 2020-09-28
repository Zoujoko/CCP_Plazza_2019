/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** ConnditionnalVar
*/

#include "ConditionnalVar.hpp"

ConditionnalVar::ConditionnalVar()
{
    pthread_cond_init(&this->_condvar, nullptr);
}

ConditionnalVar::~ConditionnalVar()
{
    pthread_cond_destroy(&this->_condvar);
}

void ConditionnalVar::signal()
{
    pthread_cond_signal(&this->_condvar);
}

void ConditionnalVar::broadcast()
{
    pthread_cond_broadcast(&this->_condvar);
}

void ConditionnalVar::wait(pthread_mutex_t *mtx)
{
    pthread_cond_wait(&this->_condvar, mtx);
}