#include<stdio.h>
#include<vector>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// maximum Value: Search for maximum value on every level in a tree.
// one thing we can do is get a 2D vector and insert every element at respect level of index
// then the answer just boils down to inserting max of every vector in the 2D vector to a 1D vector.

class Solution {
    vector<vector<int>> vals;

public:
    void insert_node(Node* node, int level) {
        if (node == NULL)
        {
            return;
        }

        if (vals.size() == level)
        {
            vals.push_back({node->data}); // for level 1
        } else {
            vals[level].push_back(node->data);
        }
        
        insert_node(node->left, level+1);
        insert_node(node->right, level+1);
        
    }

public:
    vector<int> maximumValue(Node* node) {  
        vector<int> res;
        insert_node(node, 0);
        for(auto lvl: vals) {
            res.push_back( *max_element(lvl.begin(), lvl.end()));
        }
        return res;
    }
};