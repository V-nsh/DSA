#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;

        /*
        clever way to avoid duplicates is to just ignore the number if the previous number is same,
        reason is if those two numbers didn't form a trio of 0, then they will not form in this iteration anyway
        and if they did, they will form the same trio, -1, -1 will need a 2. and if there's no 2, there's no point in checking again.
        */

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1, right = nums.size() - 1, target = -nums[i];
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    sol.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return sol;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> res = sol.threeSum(nums);

    for (auto it : res)
    {
        for (int j : it)
        {
            cout << j;
        }
        cout << endl;
    }
}