#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dups;

        for (int i = 0; i < nums.size(); i++)
        {
            if(dups.find(nums[i]) != dups.end()){
                return true;
            }else{
                dups.insert(nums[i]);
            }
        }
        return false;
    }
};