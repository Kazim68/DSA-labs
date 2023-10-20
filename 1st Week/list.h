#pragma once
#include <iostream>
using namespace std;

template<typename T>
class list {

    public:

        int size, capacity;
        T *arr;

        list();
        virtual void setCapacity();
        void append(T value);
        T &operator[](int index);
        template<typename U>
        friend ostream &operator<<(ostream &out, const list<U>& l);
        T pop();
        int len();
};