#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    /*
    brute force: consider every length and breadth of array.
    starting from the current height, check the area and take the max of current area and max seen so far.
    */
    int maxAreaBrute(vector<int> &height)
    {
        int maxSoFar = 0, left = 0, right = height.size() - 1;

        for (int i = 0; i < height.size(); i++)
        {
            left = i, right = height.size() - 1;
            while (left < right)
            {
                maxSoFar = max(maxSoFar, (min(height[left], height[right]) * (right - left))); // min because if we take the max then water won't stay in that :|, and right-left for the length.
                right--;
            }
        }
        return maxSoFar;
    }

public:
    /*
    moving the height towards the lower height we just found because we can maybe find a better height after that.
    */
    int maxArea(vector<int> &height)
    {
        int maxSoFar = 0, left = 0, right = height.size() - 1;
        while (left < right)
        {
            maxSoFar = max(maxSoFar, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxSoFar;
    }
};

int main()
{
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxAreaBrute(height);
    return 0;
}