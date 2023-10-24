#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class MinStack {
private:
    vector<int> stack;
    vector<int> mins; //keep a track of minimum value we find till ith position/opration.
    int min_val;

public:
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int val) {
        stack.push_back(val);
        mins.push_back(min(min_val, val));
        if(!mins.empty()) {
            min_val = min(mins.back(), val);
        } else {
            min_val = val;
        }
    }
    
    void pop() {
        stack.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return mins.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */