/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include <pthread.h>

class Cook {
    public:

        enum State {
            notStarted,
            working,
            finished,
        };
        Cook(const pthread_attr_t *attr, void *(*start_routine) (void *), float args);
        void start();
        void join();
        State isWorking() const;
        ~Cook();

    protected:
    private:
        const pthread_attr_t *_attr;
        pthread_t _thread;
        void *(*_func) (void *);
        float _args;
        int _ret;
        State _working;
};

#endif /* !COOK_HPP_ */
