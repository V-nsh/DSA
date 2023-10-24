#include<vector>
#include<string>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> st;
        vector<string> res;
        backTrack(n, 0, 0, st, res);
        return res;
    }

public:
    void backTrack(int n, int open, int closed, vector<char>& st, vector<string>& res) {
        if(open==n && closed==n) {
            string temp = "";
            for(char s : st) {
                temp += s;
            }
            res.push_back(temp);
            return;
        }

        if (open < n) {
            st.push_back('(');
            backTrack(n, open+1, closed, st, res);
            st.pop_back();
        }

        if(closed < open) {
            st.push_back(')');
            backTrack(n, open, closed+1, st, res);
            st.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<string> res;
    res = sol.generateParenthesis(3);
    for(string s : res) {
        cout << s;
    }

    return 0;
}