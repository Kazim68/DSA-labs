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

    public:
        Node<T> *iter;

        sl_iterator(Node<T> *p)
        {
            iter = p;
        }
        sl_iterator operator++(int)
        {
            iter = iter->next;
            return iter;
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

    sl_iterator fBegin()
    {
        return sl_iterator(head);
    }
    sl_iterator fEnd()
    {
        return sl_iterator(tail);
    }

    bool Empty()
    {
        return head == nullptr;
    }

    void splice(sl_iterator iter, LinkedList list){
        if (this->Empty()){
            head = list.head;
            tail = list.tail;
        }
        else if (iter.iter == head)
        {
            list.tail->next = head;
            head->prev = list.tail;
            head = list.head;
        }
        else if (iter.iter == tail)
        {
            tail->next = list.head;
            list.head->prev = tail;
            tail = list.tail;
        }
        else
        {
            iter.iter->prev->next = list.head;
            list.head->prev = iter.iter->prev;
            iter.iter->prev = list.tail;
            list.tail->next = iter.iter;
        }
    }
};

int main()
{
    LinkedList<int> list;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    LinkedList<int> list2;

    list2.addNode(6);
    list2.addNode(7);
    list2.addNode(8);

    list.splice(list.fEnd(), list2);

    for (LinkedList<int>::sl_iterator it = list.head; it != nullptr; it++)
    {
        cout << *it << endl;
    }


    return 0;
}

// ================= LeetCode =================

// problem 1    
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if (!list1) return list2;
    else if (!list2) return list1;

    if (list1->val <= list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else{
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

// problem 2
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int c = 0;
    if (!head->next) return head->next;
    ListNode* current = head;
    while (current){
        current = current->next;
        c++;
    }
    for (current = head; c-n > 1; c--){
        current = current->next;
    }

    if (c-n == 0) return head->next;

    if (!current->next) current = nullptr;
    else current->next = current->next->next;
    return head;
}

// problem 3
ListNode* swapPairs(ListNode* head) {
    ListNode* current = head;
    ListNode* start = new ListNode();
    ListNode* temp = start;

    if (!head || !head->next) return head;

    while (current && current->next){
        temp->next = current->next;
        current->next = temp->next->next;
        temp->next->next = current;
        temp = current;
        current = current->next;
    }
    return start->next;
}

// problem 4
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* start = new ListNode();
    start->next = head;

    ListNode* prev = start;

    for (int i = 0; i < left - 1; i++){
        prev = prev->next;
    }

    ListNode* current = prev->next;

    for (int i = 0; i < right-left; i++){
        ListNode* temp = current->next;
        current->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    return start->next;
}

// problem 5
class Node {
public:
    int val;
    Node* next;

    Node(int v){
        val = v;
        next = nullptr;
    }  
};

class MyLinkedList {
public:
    int size = 0;
    Node* head;
    Node* tail;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int index) {
        if (index >= size) return -1;
        Node* current = head;
        while (index){
            current = current->next;
            index--;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        Node* add = new Node(val);
        add->next = head;
        head = add;
        if (size == 0) tail = add;
        size++;
    }
    
    void addAtTail(int val) {
        if (size == 0){
            addAtHead(val);
            return;
        }
        Node* add = new Node(val);
        tail->next = add;
        tail = add;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        else if (index == size) addAtTail(val);
        else if (index == 0) addAtHead(val);
        else{
            Node* add = new Node(val);
            Node* current = head;
            for(int i=0; i<index-1; ++i) {
                current = current->next;
            }
            add->next = current->next;
            current->next = add;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) return;
        else if (index == size-1){
            if (index == 0){
                head == nullptr;
                tail = nullptr;
            }
            else{
                Node* temp = head;
                while (temp->next!= tail){
                    temp = temp->next;
                }
                tail = temp;
                temp->next = nullptr;
            }
        }
        else if (index == 0){
            head = head->next;
        }
        else{
            Node* current = head;
            for(int i=0; i<index-1;++i) {
                current = current->next;
            }
            current->next = current->next->next;
        }
        size--;
    }
};