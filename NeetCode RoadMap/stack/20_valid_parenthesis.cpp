#include<string>
#include<stack>
#include<iostream>

using namespace std;

class Solution {

public:
    bool helper(char a, char b) {
        return((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
    }

public:
    bool isValid(string s) {
        if (s.length() % 2 != 0)
        {
            return false;
        }
        stack<char> st;
        for(char curr: s) {
            if(curr=='(' || curr == '{' || curr=='[') {
                st.push(curr);
            } else {
                if(!st.empty() && helper(st.top(), curr)) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s =  "((";
    cout << sol.isValid(s);
    return 0;
}