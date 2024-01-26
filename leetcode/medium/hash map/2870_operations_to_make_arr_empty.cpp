#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minOperationsBrute(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        
        for (auto it: map)
        {
            if (it.second%2==0) {
                count += it.second/2;
                continue;
            } else if (it.second%3==0) {
                count += it.second/3;
                continue;
            } else {
                return -1;
            }
        }
        return count;
    }

public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        
        for (auto it: map)
        {
            if (it.second==1) {
                return -1;
            }
            count += it.second/3;
            if(it.second%3) {
                count++;
            }
        }
        return count;
    }

public:
    int minOperationsDFS(vector<int>& nums) {
        int count  = 0;
        unordered_map<int, int> map;
        unordered_map<int, int> cache;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        for(auto it: map) {
            int val = dfs(it.second, cache);
            if(val == INT_MAX) {
                return -1;
            }
            count += val;
        }
        return count;
    }

private: 
    /*
    DFS idea is to cache the results we get previously
    for 2 same numbers op = 1
        3   op = 1
        4   op = 2 = 1 + min(count(4-2 same numbers), count(4-3 same numbers))
                     ^this 1 is for the operation we do, reduce 2 or 3, then min of number of operations we do to reduce by 3 or 2.
    */
    int dfs(int count, unordered_map<int, int>& cache) {
        if(count < 2) {
            return INT_MAX;
        }
        if(count == 2 || count == 3) {
            return 1;
        }
        if(cache.find(count) != cache.end()) {
            return cache[count];
        }

        int res = min(dfs(count-2, cache), dfs(count-3, cache));
        if (res == -1){
            return -1;
        }
        cache[count] = res+1;
        return res+1;
    }

};

int main() {
    Solution sol;
    vector<int> nums = {2,3,3,2,2,4,2,3,4};
    // vector<int> nums  = {14,12,14,14,12,14,14,12,12,12,12,14,14,12,14,14,14,12,12};
    cout << sol.minOperationsDFS(nums) << endl;

    return 0;
}