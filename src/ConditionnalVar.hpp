/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** ConditionnalVar
*/

#ifndef CONDITIONNALVAR_HPP_
#define CONDITIONNALVAR_HPP_

#include <thread>

class ConditionnalVar {
    public:
        ConditionnalVar();
        ~ConditionnalVar();

        void signal();
        void broadcast();
        void wait(pthread_mutex_t *mtx);

    protected:
    private:
        pthread_cond_t _condvar;

};

#endif /* !CONDITIONNALVAR_HPP_ */
