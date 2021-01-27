#ifndef SIMPLEMOVINGAVERAGE_H
#define SIMPLEMOVINGAVERAGE_H
#include <iostream>

using namespace std;

template <typename T>
void SimpleMovingAverage(T sourceBeginIterater,T sourceEndIterater ,T meanBeginIterater,int interval)
{

    T sourceIterater=sourceBeginIterater;

    T meanIterater=meanBeginIterater;

    typename std::iterator_traits<T>::value_type mean=0;

    for(int i=0;i<interval;i++)
    {
        mean+=*sourceIterater;

        sourceIterater++;
    }

    decltype(mean) divider=interval;

    mean/=divider;

    *meanIterater=mean;

    meanIterater++;

    while(sourceIterater!=sourceEndIterater)
    {
        T firstSourceIterater=sourceIterater-interval;

        mean+=(*sourceIterater-*firstSourceIterater)/divider;

        *meanIterater=mean;

        sourceIterater++;

        meanIterater++;
    }

    return;
};

#endif // SIMPLEMOVINGAVERAGE_H
