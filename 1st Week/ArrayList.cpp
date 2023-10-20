#include <iostream>
#include "list.h"

template<typename T>
class ArrayList : public list<T>
{
public:
    ArrayList() : list<T>()
    {
        this->capacity = 2;
    }

    void setCapacity() override
    {
        this->capacity *= 1.5;
    }
};

int main()
{
    ArrayList<int> list;
    list.append(2);
    list.append(3);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);

    std::cout << list[3] << std::endl;
    std::cout << list << std::endl;
};