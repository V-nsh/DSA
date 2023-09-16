#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> frequency(nums.size()+1); //an array of array where i means the frequency of number in that position.
        unordered_map<int, int> map;
        vector<int> result;
        for(auto num: nums) {
            map[num]++; //map[num] will contain the number of times num occurs
        }
        for(auto it: map) {
            frequency[it.second].push_back(it.first); //use the map to store the number at it's frequency position.
        }

        for(int i = nums.size(); i >= 0 && k>0 ; i--) {
            while(!frequency[i].empty() && k>0) { //as long as we need to find more k elements, we push the number that occured at the highest freq in sol.
                result.push_back(frequency[i].back());
                frequency[i].pop_back();
                k--;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> res;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    // vector<int> nums = {1, 2};
    res = sol.topKFrequent(nums, 2);

    for(int it: res) {
        cout << it;
    }

    return 0;
}