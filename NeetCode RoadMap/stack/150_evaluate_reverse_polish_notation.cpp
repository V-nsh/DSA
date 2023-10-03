#include<vector>
#include<string>
#include<stack>
#include<ctype.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
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
         }
             
        }
    }
};