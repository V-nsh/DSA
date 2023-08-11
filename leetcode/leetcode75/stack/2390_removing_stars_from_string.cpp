#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        vector<char> res;
        for(auto i: s){
            if(i=='*') {
                res.pop_back();
                continue;;
            }
            res.push_back(i);
        }

        // for(auto j: res) {
        //     cout << j;
        // }

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