/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Espace de travail)
** File description:
** Mutex
*/

#include "Mutex.hpp"

Mutex::Mutex()
{
    this->_mtx = PTHREAD_MUTEX_INITIALIZER;
}

void Mutex::lock()
{
    pthread_mutex_lock(&this->_mtx);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&this->_mtx);
}

void Mutex::trylock()
{
    pthread_mutex_trylock(&this->_mtx);
}

Mutex::~Mutex()
{
}
