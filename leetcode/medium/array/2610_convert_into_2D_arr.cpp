#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    /*
    my idea is to have a vector and start filling unique values while removing the same from original vector.
    we run the loop until original vector is empty.
    we check the original vector from right to left in each iteration.
    once the pointer reaches left, we append temp to res, and clear temp.
    */
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        int i = nums.size()-1;
        vector<int> temp;
        while(!nums.empty()) {
            if(find(temp.begin(), temp.end(), nums[i]) == temp.end()) {
                temp.push_back(nums[i]);
                nums.erase(nums.begin()+i);
            }
            i--;
            if(i==-1) {
                res.push_back(temp);
                temp.clear();
                i = nums.size()-1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,4,1,2,3,1};
    vector<vector<int>> res;
    res = sol.findMatrix(nums);

    for (int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}