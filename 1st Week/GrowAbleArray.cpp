#include "vector.cpp"
#include <iostream>

template<typename T>
class GrowingArray : public Vector<T>{
    public:
    GrowingArray() : Vector<T>() {}

    void setCapacity() override {
        std::cout << "hello";
        this->capacity += 1;
    }
};

int main(){
    GrowingArray<int> list;
    list.append(6);
    cout << list;
}