#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    /*
    here, my idea is to move towards the higher number, not exactly binary search.
    while doing so we see if next number is greater than current, if so we return the current since the array is already sorted.
    */
    int findMinTwoPointer(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            if (nums[left] > nums[right])
            {
                if(nums[right-1] > nums[right]) {
                    return nums[right];
                }
                right--;
            } else {
                if(nums[left+1] > nums[left]) {
                    return nums[left];
                }
                left++;
            }
        }
        return nums[left];
    }

public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid = 0;
        while(left<right) {
            mid = left + (right-left)/2;
            if (nums[mid] > nums[right])
            {
                left = mid+1;
            } else {
                right = mid;
            }
            
        }
        return nums[left];
    }
};

int main() {
    // vector<int> nums = {3,4,5,1,2};
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution sol;
    cout << sol.findMin(nums) << endl;
    return 0;
}