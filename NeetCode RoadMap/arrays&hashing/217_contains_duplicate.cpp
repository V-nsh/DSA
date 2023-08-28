#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {

public:
/*
O(N^2) time brute force and O(1) space.
*/
    bool containsDupBrute(vector<int>& nums) {
        for(int j = 0; j< nums.size(); j++) {
            for(int i = j; i< nums.size(); i++) {
                if (nums[j]==nums[i])
                {
                    return true;
                }
                
            }
        }
        return false;
    }

public:

    /*
    Time: O(NlogN) since sorting is the only thing that we will spend time on. looking at next elements can be done in linear time.
    */
    bool containsDupSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i]==nums[i+1]) {
                return true;
            }
        }
        return false;
    }

public:
    /*
    Time: O(N) and space O(N) as we will create a hash map/set and add new elements to it and see if it already exists, searching takes O(1).
    */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dups;
        for(int i=0; i<nums.size(); i++) {
            if(dups.find(nums[i]) != dups.end()) {
                return true;
            } else {
                dups.insert(nums[i]);
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3,1};
    cout << sol.containsDuplicate(nums);
    return 0;
}