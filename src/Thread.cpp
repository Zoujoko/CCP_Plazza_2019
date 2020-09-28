/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Espace de travail)
** File description:
** Thread
*/

#include "Thread.hpp"
#include <iostream>

Thread::Thread(const pthread_attr_t *attr, void *(*function) (void *), void* args)
{
    this->_attr = attr;
    this->_func = function;
    this->_args = args;
    this->_ret = 0;
}

void Thread::start()
{
    this->_status = Thread::Status::Started;
    pthread_create(&this->_thread, this->_attr, this->_func, this->_args);
}

void Thread::join()
{
    this->_status = Thread::Status::Running;
    pthread_join(this->_thread, (void **)&this->_ret);
    // std::cout << "The return of the thread is " << this->_ret << std::endl;
    this->_status = Thread::Status::Dead;
}

Thread::Status Thread::getStatus() const
{
    return this->_status;
}

Thread::~Thread()
{
}
