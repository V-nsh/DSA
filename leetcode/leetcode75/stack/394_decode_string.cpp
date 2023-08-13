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
                string st = "";
                while((!stk.empty()) && (stk.top() != '[')) {
                    st  = stk.top()+st;
                    stk.pop();
                }
                stk.pop();
                string curr = st;
                string count = "";
                // stk.pop();
                while((!stk.empty()) && isdigit(stk.top())) {
                    count = stk.top() + count;
                    stk.pop();
                }
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