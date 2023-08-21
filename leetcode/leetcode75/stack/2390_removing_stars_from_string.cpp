#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    // if we encounter a * we skip it and remove the alphabet just before it
    // thus leet**code becomes lecode
    string removeStars(string s) {
        vector<char> res;
        for(auto i: s){
            if(i=='*') {
                // if we encounter * in string, we do not push it and also pop the element just added to the stack.
                res.pop_back();
                // skip the current loop.
                continue;
            }
            // otherwise push the character.
            res.push_back(i);
        }

        // for(auto j: res) {
        //     cout << j;
        // }

        // build string from vector
        string str(res.begin(), res.end());

        return str;
    }
};

int main() {
    string s = "leet**cod*e";
    Solution sol;

    cout << sol.removeStars(s);

    return 0;
}