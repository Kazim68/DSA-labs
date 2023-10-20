#include <iostream>
using namespace std;

template<typename T>
class Vector{
    public:
        int size, capacity;
        T* vector;

        Vector(){
            size = 0, capacity = 1;
            vector = new T[capacity];
        };

        virtual void setCapacity(){
            capacity *= 2;
        }

        void append(T value){
            if (capacity == size){
                this->setCapacity();

                T* newVector = new T[capacity];

                for (int i = 0; i < size; i++){
                    newVector[i] = vector[i];
                }

                vector = newVector;
            }

            vector[size] = value;
            size++;
        };

        T operator[](int i){
            return vector[i];
        }

        T pop(){
            size--;
            return vector[size];
        };

        int len(){
            return size;
        };
};

template <typename T>
ostream& operator<<(ostream &cout, Vector<T> &list)
{
    for (int i = 0; i < list.len(); i++)
    {
        cout << list[i] << endl;
    }
    return cout;
}