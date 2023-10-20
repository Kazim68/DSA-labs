#include "list.h"
#include <ostream>
using namespace std;

template <typename T>
list<T>::list() {
    size = 0, capacity = 1;
    arr = new T[capacity];
}

template<typename T>
void list<T>::setCapacity() {
    capacity += 1;
}

template <typename T>
void list<T>::append(T value)
{
    if (capacity == size)
    {

        setCapacity();

        T *newArr = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }

        arr = newArr;
    }

    arr[size] = value;
    size++;
};

template <typename T>
T& list<T>::operator[](int index)
{
    return arr[index];
}

template <typename T>
ostream& operator<<(ostream& cout, const list<T>& l)
{
    for (int i = 0; i < l.len(); i++)
    {
        cout << l[i] << endl;
    }
    return cout;
}

template <typename T>
T list<T>::pop()
{
    size--;
    return arr[size];
}


template <typename T>
int list<T>::len()
{
    return size;
};

// m.faraz@uet.edu.pk