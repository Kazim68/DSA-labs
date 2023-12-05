#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        int balance = height(root->left) - height(root->right);
        return abs(balance) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int left = height(node->left);
        int right = height(node->right);

        return max(left, right) + 1;
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        storeInVector(root, nodes);

        return balance(nodes, 0, nodes.size()-1);
    }

    void storeInVector(TreeNode* node, vector<TreeNode*> &nodes){
        if (node == nullptr) return;

        storeInVector(node->left, nodes);
        nodes.push_back(node);
        storeInVector(node->right, nodes);
    }

    TreeNode* balance(vector<TreeNode*> &nodes, int start, int end){
        if (start > end) return nullptr;

        int mid = (end + start) / 2;

        TreeNode* node = nodes[mid];

        node->left = balance(nodes, start, mid-1);
        node->right = balance(nodes, mid+1, end);

        return node;
    }
};