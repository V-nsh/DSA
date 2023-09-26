#include "BinaryTree.h"
#include<vector>

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

/*
I am a stupid fuck.
*/
class Solution {
public:
    int goodNodes(TreeNode* root) {
        // read this in the hint, we can solve this by keeping track of the maximum node so far.
        /*
        so I guess if the current node is greater than max, we can increase the count and change the current max.
        */
       if (root == nullptr)
       {
        return 0;
       }
    }
};

int main() {
    Solution sol;
    Tree tree;

    /*
    test case 1
    */
    // TreeNode *root = tree.createNode(3);
    // root->left = tree.createNode(1);
    // root->right = tree.createNode(4);
    // root->left->left = tree.createNode(3);
    // root->right->right = tree.createNode(5);
    // root->right->left = tree.createNode(1);

    /*
    test case 4
    */
    TreeNode *root = tree.createNode(1);
    root->left = tree.createNode(4);
    root->left->left = tree.createNode(6);
    root->left->left->right = tree.createNode(10);

    std::cout << sol.goodNodes(root);
    // tree.levelOrder(root);
    return 0;
}