#include <random>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "simplemovingaverage.h"
#include <chrono>

using namespace std;

typedef  float REAL;

#define DEF_RANDOM

int main()
{
    int numberValues=1000000;

    vector<int> interval_sets={4,8,16,32,64,128};

    for( vector<int>::iterator it_interval=interval_sets.begin();
         it_interval!=interval_sets.end();
         it_interval++)
    {

    ///Размер окна усреднения
    int interval=*it_interval;

#ifdef DEF_RANDOM
    ///Создание случайного набора данных для заполнения вектора

    random_device rnd_device;

    mt19937 mersenne_engine {rnd_device()};

    uniform_real_distribution<REAL> dist{-2.f, 6.f};

    auto gen = [&dist, &mersenne_engine](){
        return dist(mersenne_engine);
    };
    ///Вектор входных значений
    vector<REAL> v_in(numberValues);

    ///Инициализация вектора случайным набором
    generate(begin(v_in), end(v_in), gen);
#else
    vector<REAL> v_in={1.f,2.f,3.f,4.f,5.f,6.f,7.f,8.f,9.f,10.f};
#endif

    ///Выходной вектор размером n-interval+1
    vector<REAL> v_out(v_in.size()-interval+1);


    auto start = chrono::steady_clock::now();

    ///Алгоритм простого скользящего среднего
    SimpleMovingAverage(v_in.begin(),v_in.end(),v_out.begin(),interval);

    auto end = chrono::steady_clock::now();


    ///Затраченное процессорное время

    chrono::duration<double> elapsed_seconds = end-start;

    ///Производительность
    double performance=numberValues/elapsed_seconds.count();

    cout<< std::fixed;

    cout<< "performance: " << performance <<"\n";

#ifndef DEF_RANDOM

    vector<REAL>::iterator it=v_out.begin();

    while(it!=v_out.end())
        cout << *(it++) << endl;
#endif
    }

    return 0;
}
