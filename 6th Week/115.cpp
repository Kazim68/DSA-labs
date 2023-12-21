#include <iostream>
using namespace std;


// question 1

template<typename T>
class Node {
    public:
        T data;
        Node<T> *next;
        Node<T> *prev;

        Node() {
            data = 0;
            next = nullptr;
            prev = nullptr;
        }

        Node(T val){
            data = val;
            next = nullptr;
        }
};

template<typename T>
class LinkedList {
    public:
        Node<T> *head;
        Node<T> *tail;

        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        bool isEmpty(){
            return head == nullptr;
        }

        void insertAtTail(T val){
            Node<T> *newNode = new Node<T>(val);
            if (isEmpty()){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        void insertAtHead(T val){
            Node<T> *newNode = new Node<T>(val);
            if (isEmpty()){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
        }

        Node<T>* getMiddleNode(){
            Node<T> *current = head;
            int c = 0;
            while (current != nullptr){
                c++;
                current = current->next;
            }
            current = head;
            for (int i = 0; i < c/2; i++){
                current = current->next;
            }
            return current;
        }

        void insertAtMiddle(T val){
            Node<T>* temp = new Node<T>(val);
            if (isEmpty()){
                head = temp;
                tail = temp;
            }
            else{
                Node<T>* current = getMiddleNode();
                temp->next = current->next;
                current->next = temp;
            }
        }

        void insertAfter(T value, T key){
            Node<T>* temp = new Node<T>(value);
            if (isEmpty()){
                head = temp;
                tail = temp;
            }
            else{
                Node<T>* current = head;
                while (current != nullptr){
                    if (current->data == key){
                        temp->next = current->next;
                        current->next = temp;
                    }
                }
            }
        }

        void insertBefore(T value, T key){
            Node<T>* temp = new Node<T>(value);
            if (isEmpty()){
                head = temp;
                tail = temp;
            }
            else{
                Node<T>* current = head;
                while(current != nullptr){
                    if (current->next->data == key){
                        temp->next = current->next;
                        current->next = temp;
                    }
                }
            }
        }

        T GetFront(){
            return isEmpty() ? -1 : head->data;
        }

        T GetBack(){
            return isEmpty() ? -1 : tail->data;
        }

        Node<T>* Search(T value){
            Node<T>* current = head;
            while (current != nullptr){
                if (current->data == value){
                    return current;
                }
                current = current->next;
            }
            return nullptr;
        }

        void RemoveFront(){
            if (isEmpty()){
                return;
            }
            else if (head->next == nullptr){
                head = nullptr;
                tail = nullptr;
            }
            else{
                head = head->next;
            }
        }

        void RemoveLast(){
            if (isEmpty())
                return;
            else if (tail->prev == nullptr){
                head = nullptr;
                tail = nullptr;
            }
            else{
                tail = tail->prev;
            }
        }

        void RemoveMiddle(){
            if (isEmpty())
                return;
            else if (head->next == nullptr){
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node<T>* current = getMiddleNode();
                current->next = current->next->next;
            }
        }
};

// question 2

template<typename T>
class Stack{
    public:
        LinkedList<T> *list;

        Stack(){
            list = new LinkedList<T>();
        }

        bool isEmpty(){
            return list->isEmpty();
        }

        void push(T value){
            list->insertAtHead(value);
        }

        T pop(){
            T *temp = list->head->data;
            list->RemoveLast();
        }
};

template<typename T>
class Queue{
    public:
        LinkedList<T> *list;

        Queue(){
            list = new LinkedList<T>();
        }

        bool isEmpty(){
            return list->isEmpty();
        }

        void enqueue(T value){
            list->insertAtTail(value);
        }

        T dequeue(){
            T *temp = list->head->data;
            list->RemoveFront();
        }
};

// question 3

// part a
template<typename T>
void printFront(Node<T>* current){
    if (current->next == nullptr){
            cout << current->data;
            return;
    }
    else{
        cout << current->data << "->";
        printFront(current->next);
    }
}

template<typename T>
void printLLFront(LinkedList<T> &list){
    printFront(list.head);
}

template<typename T>
void printBack(Node<T> &current){
    if (current.prev == nullptr){
        cout << current->data;
        return;
    }
    else{
        cout << current->data << " ";
        printBack(current->prev);
    }
}

template<typename T>
void printLLBack(LinkedList<T> &list){
    printBack(list.tail);
}

// part b
template<typename T>
T getMiddleElement(LinkedList<T> &list){
    Node<T> *current = list->head;
    Node<T> *fast = list->head;
    while (fast != nullptr && fast->next != nullptr){
        current = current->next;
        fast = fast->next->next;
    }
    return current->data;
}

// part c
template<typename T>
bool isCircular(LinkedList<T> &list){
    return list.tail->next == list.head;
}

// part d
template<typename T>
void reverseLL(LinkedList<T>& list){
    Node<T> *current = list.head;
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;
    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    Node<T> *temp = list.head;
    list.head = prev;
    list.tail = temp;
}

int main(){
    LinkedList<int> list;   
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    printLLFront(list);
    cout << endl;
    reverseLL(list);
    printLLFront(list);
}