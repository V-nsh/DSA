#include<iostream>
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree {

public:
    TreeNode* createRoot(int val) {
        return new TreeNode(val);
    }

public:
    TreeNode* insertNodeBST(TreeNode*& root, int val) {
        if(root==nullptr) {
            return createRoot(val);
        }

        if(val > root->val) {
            root->right = insertNodeBST(root->right, val);
        } else {
            root->left = insertNodeBST(root->left, val);
        }
        return root;
    }

public:
    TreeNode* insertNode(TreeNode*& root, int val) {
        if(root==nullptr){
            return createRoot(val);
        }
        std::vector<TreeNode*> queue;
        queue.push_back(root);

        while(!queue.empty()) {
            TreeNode* current = queue.front();
            queue.erase(queue.begin());
            if(current->left!=nullptr) {
                queue.push_back(current->left);
            } else {
                current->left = createRoot(val);
                return root;
            }

            if(current->right!=nullptr) {
                queue.push_back(current->right);
            } else {
                current->right = createRoot(val);
                return root;
            }
        }
        return root;
    }

public:
    void levelOrder(TreeNode*& root) {
        if(root==nullptr) {
            std::cout << "";
        }
        std::vector<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty()) {
            TreeNode* current = queue.front();
            queue.erase(queue.begin());
            std::cout << current->val << " ";
            if(current->left != nullptr) {
                queue.push_back(current->left);
            }
            if(current->right!=nullptr) {
                queue.push_back(current->right);
            }
        }
    }
};

int main() {
    Tree tree;
    TreeNode* root = tree.createRoot(3);
    root = tree.insertNode(root, 2);
    root = tree.insertNode(root, 4);
    root = tree.insertNode(root, 1);
    tree.levelOrder(root);
    return 0;
}