#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;
        int height;

        Node(int data) {
            this->data = data;
            left = right = nullptr;
            height = 1;
        }
};

class AVL {
    public:
        Node *root;
        AVL() {
            root = nullptr;
        }

        // Get height of node
        int height(Node *node){
            if (node == nullptr)
                return 0;
            return node->height;
        }

        // Get max of two integers
        int max(int a, int b){
            return (a > b) ? a : b;
        }

        // check balance of avl tree
        int getBalance(Node* node){
            if (node == nullptr)
                return 0;
            return height(node->left) - height(node->right);
        }

        // right rotate
        Node* rightRotate(Node* y){
            Node *x = y->left;
            Node *T2 = x->right;

            x->right = y;
            y->left = T2;

            y->height = max(height(y->left), height(y->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;

            return x;
        }

        // left rotate
        Node* leftRotate(Node* x){
            Node *y = x->right;
            Node *T2 = y->left;

            y->left = x;
            x->right = T2;

            x->height = max(height(x->left), height(x->right)) + 1;
            y->height = max(height(y->left), height(y->right)) + 1;

            return y;
        }

        // insert into AVL tree
        Node* insert(Node* node, int data){

            // normal bst insertion
            if (node == nullptr) return new Node(data);

            if (data < node->data)
                node->left = insert(node->left, data);
            else if (data > node->data)
                node->right = insert(node->right, data);
            else return node;

            // update height of ancestor node
            node->height = max(height(node->left), height(node->right)) + 1;

            // check balance
            int balance = getBalance(node);

            // if unbalanced, there are 4 cases
            if (balance > 1 && data < node->left->data)
                return rightRotate(node);
            else if (balance < -1 && data > node->right->data)
                return leftRotate(node);
            else if (balance > 1 && data > node->left->data){
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            else if (balance < -1 && data < node->right->data){
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            // finally we return node
            return node;
        }

        // minimum value of tree
        Node* minValueNode(Node* node){
            Node *current = node;
            while (current->left != nullptr)
                current = current->left;
            return current;
        }

        // deleting node from tree
        Node* deleteNode(Node* node, int data){
            
            // normal bst deletion
            if (node == nullptr) return node;
            else if (data > node->data)
                node->right = deleteNode(node->right, data);
            else if (data < node->data)
                node->left = deleteNode(node->left, data);
            else{
                if (!node->left)
                    return node->right;
                else if (!node->right)
                    return node->left;
                else{
                    Node *temp = minValueNode(node->right);
                    node->data = temp->data;
                    node->right = deleteNode(node->right, temp->data);
                }
            }

            // update height of current node
            node->height = max(height(node->left), height(node->right)) + 1;

            // check balance
            int balance = getBalance(node);

            // if unbalanced, there are 4 cases

            // left left case
            if (balance > 1 && getBalance(node->left) >= 0)
                return rightRotate(node);
            
            // left right case
            if (balance > 1 && getBalance(node->left) < 0){
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // right right case
            if (balance < -1 && getBalance(node) <= 0)
                return leftRotate(node);
            
            // right left case
            if (balance < -1 && getBalance(node) > 0){
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            return node;
        }

        // searching in avl tree
        Node* search(Node* node, int val){
            if (node == nullptr || node->data == val)
                return node;
            if (node->data < val) return search(node->right, val);
            return search(node->left, val);
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

int main(){

    AVL avl;

    avl.root = avl.insert(avl.root, 10);
    avl.root = avl.insert(avl.root, 20);
    avl.root = avl.insert(avl.root, 30);
    avl.root = avl.insert(avl.root, 40);
    avl.root = avl.insert(avl.root, 50);
    avl.root = avl.insert(avl.root, 25);

    avl.printTree(avl.root);

    avl.root = avl.deleteNode(avl.root, 30);
    cout << endl
         << endl;

    avl.printTree(avl.root);
    return 0;
}