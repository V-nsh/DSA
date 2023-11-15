#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = 0, left = 0, right = nums.size()-1;
        while(left<=right) {
            mid = left+(right-left) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return -1;
    }
};

int main() {
    int target = 9;
    vector<int> nums = {-1,0,3,5,9,12};
    Solution sol;
    cout << sol.search(nums, 9);
    return 0;
}