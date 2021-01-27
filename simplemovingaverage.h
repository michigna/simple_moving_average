#ifndef SIMPLEMOVINGAVERAGE_H
#define SIMPLEMOVINGAVERAGE_H
#include <iterator>

using namespace std;

template <typename T>
void SimpleMovingAverage(T sourceBeginIterater,T sourceEndIterater ,T meanBeginIterater,int interval)
{
    // Текущий итератор исходной последовательности
    T sourceIterater=sourceBeginIterater;

    // Текущий итератор усреднённой последовательности
    T meanIterater=meanBeginIterater;

    //Переменная среднего текущего значения того же типа данных, как указывает итератор  T
    typename std::iterator_traits<T>::value_type mean=0;

    //Расчёт суммы для первых значений
    for(int i=0;i<interval;i++)
    {
        mean+=*sourceIterater;

        sourceIterater++;
    }

    decltype(mean) divider=interval;

    //Расчёт первого среднего значения
    mean/=divider;


    //Запоминаем в выходную последовательность
    *meanIterater=mean;

    meanIterater++;

    while(sourceIterater!=sourceEndIterater)
    {
        //Вычисление итератора на n-interval элемент
        T firstSourceIterater=sourceIterater-interval;

        //Рекурентная запись для скользящего среднего. К предыдущему среднему добавляем новое значение, вычитаем n-interval значение и делим на количество элементов в окне
        mean+=(*sourceIterater-*firstSourceIterater)/divider;

        //Запоминаем в выходную последовательность
        *meanIterater=mean;

        sourceIterater++;

        meanIterater++;
    }

    return;
};

#endif // SIMPLEMOVINGAVERAGE_H
