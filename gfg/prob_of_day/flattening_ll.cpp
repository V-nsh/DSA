#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
public:
    Node *flatten(Node *root) {

    }
};