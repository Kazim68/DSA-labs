#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right, *parent;
        string color;

        Node(int data){
            this->data = data;
            left = right = parent = NULL;
            color = "R";
        }
};

class RedBlackTree{
    public:
        Node *root;
        bool ll, lr, rl, rr;

        RedBlackTree(){
            root = NULL;
            ll = lr = rl = rr = false;
        }

        // right rotation
        Node* rightRotate(Node* node){

        }

        // left rotation
        Node* leftRotate(Node* node){

        }

        // insert node
        Node* insert(int data){
            
        }

        // printing AVL tree
        void printTree(Node* current, int space = 0){
            if (!current){
                return;
            }

            printTree(current->right, space + 10);
            
            for (int i = 0; i < space; i++){
                cout << " ";
            }

            cout << current->data << endl;

            printTree(current->left, space + 10);

        }
};