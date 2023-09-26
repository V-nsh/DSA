#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestConsecutiveNlogN(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int lcs = 1, temp = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            while (i < nums.size() && (nums[i] - nums[i - 1] <= 1) && (nums[i] - nums[i - 1] >= 0))
            {
                if (nums[i] - nums[i - 1] == 1)
                {
                    temp++;
                    i++;
                    lcs = max(lcs, temp);
                }
                else
                {
                    i++;
                }
            }
            temp = 1;
        }
        return lcs;
    }

public:
    int longestConsecutiveSet(vector<int> &nums)
    {
        /*
        add all the elements to a set and add the element only if it starts a sequence.
        */
        if (nums.size() == 0)
        {
            return 0;
        }
        unordered_set<int> set(nums.begin(), nums.end());
        int maxSoFar = 1, temp = 1;
        for (int num : set)
        {
            if (set.find(num - 1) == set.end())
            {
                int next = num + 1;
                while (set.find(next) != set.end())
                {
                    maxSoFar = max(maxSoFar, ++temp);
                    next++;
                    // j++;
                }
            }
            temp = 1;
        }
        return maxSoFar;
    }
};

int main()
{
    Solution sol;
    // vector<int> nums = {100, 4, 200, 1, 3, 2};
    // vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> nums = {0, -1};
    cout << sol.longestConsecutiveSet(nums);
    return 0;
}