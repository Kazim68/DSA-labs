#include <iostream>
using namespace std;

enum Color {RED, BLACK};

class Node{
    public:
        int data;
        Node *left, *right, *parent;
        Color color;

        Node(int data){
            this->data = data;
            left = right = parent = NULL;
            color = RED;
        }

        // get uncle
        Node* uncle(){
            if (parent == nullptr || parent->parent == nullptr){
                return nullptr;
            }
            if (parent->isOnLeft()){
                // uncle must be on right
                return parent->parent->right;
            }
            // uncle must be on left
            return parent->parent->left;
        }

        // checking for left sibling
        bool isOnLeft(){
            return this == parent->left;
        }

        // return sibling
        Node* sibling(){
            if (parent == nullptr){
                return nullptr;
            }
            if (isOnLeft()){
                return parent->right;
            }
            return parent->left;
        }

        // check for a red child node
        bool hasRedChild(){
            return (left != nullptr && left->color == RED) || (right != nullptr && right->color == RED);
        }

        // move down 
        void moveDown(Node* node){
            if (parent != nullptr){
                if (isOnLeft()){
                    parent->left = node;
                }
                else {
                    parent->right = node;
                }
            }
            node->parent = parent;
            parent = node;
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
            Node *x = node->left;
            Node *y = x->right;

            x->right = node;
            node->left = y;
            node->parent = x;

            if (y != nullptr){
                y->parent = node;
            }

            return x;
        }

        // left rotation
        Node* leftRotate(Node* node){
            Node *x = node->right;
            Node *y = x->left;

            x->left = node;
            node->right = y;
            node->parent = x;

            if (y != nullptr){
                y->parent = node;
            }

            return x;
        }

        // checking for Red Red violation
        bool redRedViolation(Node* node){
            if (node != root && node->color == RED && node->left->color == RED){
                return true;
            }
            return false;
        }

        // insert node
        Node* insert(int data){
            if (root == nullptr){
                root = new Node(data);
                root->color = BLACK;
                return root;
            }
            root = insert(root, data);
            return root;
        }

        // insert function overload
        Node* insert(Node* node, int data){
            bool flag = false;

            // normal bst insert
            if (node == nullptr)
                return new Node(data);
            else if(data < node->data){
                node->left = insert(node->left, data);
                node->left->parent = node;
                if (node != root && node->color == RED && node->left->color == RED){
                    flag = true;
                }
            }
            else{
                node->right = insert(node->right, data);
                node->right->parent = node;
                if (node != root && node->color == RED && node->right->color == RED){
                    flag = true;
                }
            }

            // rotation
            if (ll){
                // left left rotation
                node = leftRotate(node);
                node->color = BLACK;
                node->left->color = RED;
                ll = false;
            }
            else if (lr){
                // left right rotation
                node->left = leftRotate(node->left);
                node->left->parent = node;
                node = rightRotate(node);
                node->color = BLACK;
                node->right->color = RED;
                lr = false;
            }
            else if (rr){
                // right right rotation
                node = rightRotate(node);
                node->color = BLACK;
                node->right->color = RED;
                rr = false;
            }
            else if(rl) {
                // right left rotation
                node->right = rightRotate(node->right);
                node->right->parent = node;
                node = leftRotate(node);
                node->color = BLACK;
                node->left->color = RED;
                rl = false;
            }

            // handle red red violation
            if(flag){
                if (node->parent->right == node){
                    // this is the right child

                    if (node->parent->left == nullptr || node->parent->left->color == BLACK){
                        // uncle is black
                        if (node->left != nullptr && node->left->color == RED){
                            // right left violation
                            rl = true;
                        }
                        else if (node->right != nullptr && node->right->color == RED){
                            // left left violation
                            ll = true;
                        }
                    }
                    else{
                        // uncle is red
                        node->parent->left->color = BLACK;
                        node->color = BLACK;
                        if (node->parent != root){
                            node->parent->color = RED;
                        }
                    }
                }
                else{
                    // this is the left child

                    if (node->parent->right == nullptr || node->parent->right->color == BLACK){
                        // uncle is black
                        if (node->left != nullptr && node->left->color == RED){
                            // right right violation
                            rr = true;
                        }
                        else if (node->right != nullptr && node->right->color == RED){
                            // left right violation
                            lr = true;
                        }
                    }
                    else{
                        // uncle is red
                        node->parent->right->color = BLACK;
                        node->color = BLACK;
                        if (node->parent != root){
                            node->parent->color = RED;
                        }
                    }
                }
                flag = false;
            }

            return node;
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

    RedBlackTree tree;

    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    tree.insert(8);
    tree.insert(2);
    tree.insert(9);

    tree.printTree(tree.root);
}