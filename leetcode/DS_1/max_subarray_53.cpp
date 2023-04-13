#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return mSub(nums, 0, nums.size()-1); 
    }
    
public:
    int mCrossing(vector<int>& nums, int p, int q, int r){
        int sum_left = nums[q];
        int sum_right = nums[q+1];
        int curr_sum = sum_left;
        for (int i = q-1; i >= p; i--)
        {
            curr_sum += nums[i];
            sum_left = max(sum_left, curr_sum);
        }

        curr_sum = sum_right;
        for (int j = q+2; j <= r; j++)
        {
            curr_sum += nums[j];
            sum_right = max(curr_sum, sum_right);
        }
        

        return sum_left+sum_right;
    }

public:
    int mSub(vector<int>& nums, int p, int r){
        if (p==r)
        {
            return nums[p];
        }

        int q = p + (r-p)/2;

        int L = mSub(nums, p, q);
        int R = mSub(nums, q+1, r);
        int C = mCrossing(nums, p, q, r);
        
        return max({L, R, C});
    }
};