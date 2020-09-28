/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Espace de travail)
** File description:
** Thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_
#include <pthread.h>

class Thread {
    public:

        enum Status {
            Started,
            Running,
            Dead,
        };
        Thread(const pthread_attr_t *attr, void *(*start_routine) (void *), void *args);
        void start();
        void join();
        Status getStatus() const;

        ~Thread();

    protected:
    private:
        Status _status;
        const pthread_attr_t *_attr;
        pthread_t _thread;
        void *(*_func) (void *);
        void *_args;
        int _ret;
};

#endif /* !THREAD_HPP_ */
