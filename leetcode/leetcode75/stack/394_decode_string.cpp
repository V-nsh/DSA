#include<string>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        string build = "";
        for(char c: s) {
            if (c!=']')
            {
                stk.push(c);
            } else if (c==']') {
                // the string we need to build for reps
                string st = "";
                while((!stk.empty()) && (stk.top() != '[')) { //if we encounter a [, there will definitely be a digit below that
                    st  = stk.top()+st;
                    stk.pop();
                }
                stk.pop();
                string curr = st;
                string count = "";
                // build the string
                while((!stk.empty()) && isdigit(stk.top())) {
                    count = stk.top() + count;
                    stk.pop();
                }
                // count amount of times
                int cnt = stoi(count)-1;
                while(cnt) {
                    st += curr;
                    cnt--;
                }
                for(int i=0; i<st.length(); i++) {
                    stk.push(st[i]);
                }
            }
        }

        while(!stk.empty()) {
            build = stk.top() + build;
            stk.pop();
        }

        return build;
    }
};

int main() {
    Solution sol;
    // string s = "3[a]2[bc]";
    // string s = "3[a2[c]]";
    string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    cout << sol.decodeString(s);

    return 0;
}