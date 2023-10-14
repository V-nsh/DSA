#include<vector>
#include<string>
#include<stack>
#include<ctype.h>
#include<unordered_map>
#include<functional>
#include<iostream>

using namespace std;

class Solution {
public:
    /*
    Not like I came up with this but had a similar idea, just didn't know we can add functions to a hashmap.
    <int (int, int) > means return type int with two parameters int, int.
    */  
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, std::function<int (int, int)> > map = {
            /*
             general structure of lambda functions
             [ capture-list ] ( parameters ) -> return-type {
                    // Lambda function body
                }
            */
            {"+", [] (int a, int b) -> int {return a+b;}}, 
            {"-", [] (int a, int b) {return a-b;}},
            {"*", [] (int a, int b) {return a*b;}},
            {"/", [] (int a, int b) {return a/b;}},
        };
        for(string tk: tokens) {
         if (tk != "-" && tk != "+" && tk != "*" && tk != "/")
         {
            int num = stoi(tk);
            st.push(num);
         } else {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            std::function<int(int, int)>  op = map[tk];
            st.push(op(second, first)); 
         }
        }
        return st.top();
    }
};

int main() {
    vector<string> tokens = {"2","1","+","3","*"};
    Solution sol;

    cout << sol.evalRPN(tokens);
    return 0;
}