#ifndef LOCKER_H
#define LOCKER_H
#include <pthread.h>


class Locker
{
    public:
        Locker();
        int start;
        int endd;
        int lock = 0;


        pthread_mutex_t mutex;
		pthread_cond_t lockCondition;

        virtual ~Locker();

    protected:

    private:
};

#endif // LOCKER_H
