#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ns;
        vector<int> sol;

        for (int i = 0; i < nums.size(); i++)
        {
            int num2 = target - nums[i];

            if (ns.find(num2) != ns.end()) //if you find the number in the hashmap
            {
                sol.push_back(ns[num2]);
                sol.push_back(i);
                return sol;
            }
            ns[nums[i]] = i;
        }
        return sol;
    }
};