/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Cook
*/

#include "Cook.hpp"
#include <iostream>

Cook::Cook(const pthread_attr_t *attr, void *(*function) (void *), float args)
{
    this->_attr = attr;
    this->_func = function;
    this->_args = args;
    this->_ret = 0;
    this->_working = State::notStarted;
}

// Thread start
void Cook::start()
{
    pthread_create(&this->_thread, this->_attr, this->_func, &this->_args);
    this->_working = State::working;
}

// Thread join
void Cook::join()
{
    pthread_join(this->_thread, (void **)&this->_ret);
    this->_working = State::finished;
}

// Returns TRUE if the cook is currently making a pizza
Cook::State Cook::isWorking() const
{
    return (this->_working);
}

Cook::~Cook()
{
}