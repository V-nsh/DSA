#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {

public:
    vector<int> twoSumBrute(vector<int>& nums, int target) {
        vector<int> sol;
        for(int i =0; i< nums.size()-1; i++) {
            for(int j = i+1; j< nums.size(); j++) {
                if(nums[i]+nums[j]==target) {
                    sol.push_back(i);
                    sol.push_back(j);
                    cout << sol[0] << " " << sol[1] << endl;
                    return sol;
                }
            }
        }
        return sol;
    }

public:
    /*
    the classic, again.
    we're filling the map on the go, and that's why it works, since it doesn't see the value at same index again.
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; //we will store in this way value: index since the result wants the indices of the values that give the target.
        vector<int> sol;

        for(int i=0; i< nums.size(); i++) {
            int num2 = target-nums[i];
            if (map.find(num2) != map.end()) // see if num2 exists.
            {
                sol.push_back(i);
                sol.push_back(map[num2]);
                return sol;
            }
            map[nums[i]] = i; //if not we continue by adding the number we just saw.
        }

        return sol;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    sol.twoSumBrute(nums, 9);
    return 0;
}