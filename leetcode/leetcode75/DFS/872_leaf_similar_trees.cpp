#include<iostream>
#include<vector>
#include "BinaryTree.h"

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {

public:
    std::vector<int> finalLevelOrder(TreeNode*& root) {
        if(root==nullptr) {
            return {};
        }
        // the way I am implement insertion here does not match the problem's. stack works because the sequence matters 
        // hence going to the bottom of each branch is just better.
        /*
            if we had a queue level order traversal  for a tree like this

                                        3
                                    /       \
                                5               1
                            /       \           /   \
                            7        2          6     4
                                /       \
                                8       9

        see here level order will first take into consideration the leaf nodes that are a level above the leaf nodes of node with value 2.
                                        3
                                    /       \
                                5               1
                            /       \           /   \
                            7       8           2    4
                                             /     \
                                            9       6
        now if 2 was over here the sequence changes. see the leaf nodes are the same when we SEE them but not if we do a level order search.
        if we do a DFS instead it will reach each and every leaf first instead of traversing the entire level.

        because in first example the BFS/ level order search will give leaf nodes as 7, 6, 4, 8, 9.
        and the second tree has 7, 8, 4, 9, 6.
        sorting will just increase complexity.
        */
        std::vector<TreeNode*> stack;
        stack.push_back(root);
        std::vector<int> finalLevel;
        while(!stack.empty()) {
            TreeNode* current = stack.back();
            stack.pop_back();
            if(current->left==nullptr && current->right==nullptr){
                finalLevel.push_back(current->val);
            }
            if (current->left != nullptr)
            {
            stack.push_back(current->left);
            }
            
            if(current->right != nullptr) {
            stack.push_back(current->right);
            }
        }
        return finalLevel;
    }

public:
    bool leafSimilar(TreeNode*& root1, TreeNode*& root2) {
        std::vector<int> leafNodes1 = finalLevelOrder(root1);
        std::vector<int> leafNodes2 = finalLevelOrder(root2);

        for(auto it : leafNodes1) {
            std::cout << it << " ";
        }

        std::cout << "\n";

        for(auto it1 : leafNodes2) {
            std::cout << it1 << " ";
        }

        std::cout << "\n";

        return leafNodes1 == leafNodes2;
    }
};

int main() {
    Solution solution;
    Tree tree;

    TreeNode* root1 = nullptr;
    TreeNode* root2 = nullptr;
    
    root1 = tree.insertNode(root1, 3);
    root2 =  tree.insertNode(root2, 3);


    root1 = tree.insertNode(root1, 5);
    root1 = tree.insertNode(root1, 1);
    root1 = tree.insertNode(root1, 6);
    root1 = tree.insertNode(root1, 2);
    root1 = tree.insertNode(root1, 9);
    root1 = tree.insertNode(root1, 8);
    root1 = tree.insertNode(root1, 7);
    root1 = tree.insertNode(root1, 4);


    root2 = tree.insertNode(root2, 2);
    root2 = tree.insertNode(root2, 3);
    root2 = tree.insertNode(root2, 0); 

    bool result = solution.leafSimilar(root1, root2);
    if (result) {
        std::cout << "Leaf nodes are similar." << std::endl;
    } else {
        std::cout << "Leaf nodes are not similar." << std::endl;
    }
    
    return 0;
}