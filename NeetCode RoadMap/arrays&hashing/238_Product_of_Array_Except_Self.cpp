#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol(nums.size(), 1);
        int right = nums[nums.size()-1];
        for(int i=1; i<nums.size(); i++) { //i=1 since there's no number before first
            sol[i] = sol[i-1] * nums[i-1]; //first multiply with all the numbers on left.
        }

        for(int j = nums.size()-2; j>=0; j--) {//keep a track of the right side product until current, sol[i] is the product of all elements towards left of i.
            sol[j] = sol[j]*right;
            right *= nums[j];
        }

        return sol;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = sol.productExceptSelf(nums);
    for(auto it: res) {
        cout << it << " ";
    }
    return 0;
}