#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    // Node(){}

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void addNode(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }

    class sl_iterator
    {
        Node<T> *iter;

    public:
        sl_iterator(Node<T> *p)
        {
            iter = p;
        }
        sl_iterator operator++(int)
        {
            iter = iter->next;
            return iter;
        }
        sl_iterator fBegin()
        {
            return head;
        }
        sl_iterator fEnd()
        {
            return tail;
        }

        bool operator==(const sl_iterator &other)
        {
            return iter == other.iter;
        }
        
        bool operator!=(const sl_iterator &other)
        {
            return iter != other.iter;
        }

        T operator*()
        {
            return iter->data;
        }
    };
};

int main()
{
    LinkedList<int> list;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    for (LinkedList<int>::sl_iterator it = list.head; it != nullptr; it++)
    {
        cout << *it << endl;
    }

    return 0;
}