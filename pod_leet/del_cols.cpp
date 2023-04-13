#include<iostream>
#include<vector>

using namespace std;

// problem 944

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        for (int i = 0; i < strs.size()-1; i++)
        {
         for (int j = 0; j < strs[i].size()-1; j++)
            {
                if (strs[i][j] > strs[i+1][j])
                {
                    count++;
                }
                
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<string> str = {"cba","daf","ghi"};
    int ans = sol.minDeletionSize(str);
    cout << ans;
    return 0;
}