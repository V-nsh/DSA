#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    /*
    the element can either be in left sorted part or right rotated part, so we first see where our middle is right now.
    it can be in right or left, but in either case we need to see which part of that region we want to consider.
    say we are in left sorted array meaning there's a rotated part on right so we need to see if the target is in left or right.
    if we are on right sorted part then we do a simple binary search on it.
    */
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid = 0;
        while(left<=right) {
            mid = left + (right-left)/2;
            if(nums[mid] == target) {
                return mid;
            }else if(nums[mid] > nums[right]) { // we are in left sorted array
                if(target < nums[mid] && target >= nums[left]) { //if the target is in left sorted part
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                if(target > nums[mid] && target <= nums[right]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
            
        }
        return -1;
    }
};

int main() {
    // vector<int> nums = {4,5,6,7,0,1,2};
    // int target = 5;
    vector<int> nums = {5, 1, 3};
    int target = 5;
    // vector<int> nums = {1};
    // int target = 1;
    Solution sol;
    cout << sol.search(nums, target) << endl;

    return 0;
}