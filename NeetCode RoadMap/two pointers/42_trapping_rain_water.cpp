#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    /*
    this is just about finding the maxLeft and maxRight, we take the min(left, right) from i - height[i] and that's how many units of water ith position can hold.
    sum up all these units and we get our answer.
    I WOULD NOT FIND THIS BY MYSELF IN A MILLION YEARS WTF.

    so the intuition is how many units the current unit can hold VERTICALLY
    */
    int trapMem(vector<int> &height)
    {
        vector<int> maxLeft, maxRight(height.size(), 0);
        int water = 0, temp = 0;
        maxLeft.push_back(0);
        int left = height[0], right = height.back();
        for(int i = 1; i< height.size(); i++) {
            left = max(left, height[i-1]);
            maxLeft.push_back(left);
        }

        for (int i = height.size()-2; i >= 0; i--)
        {
            right = max(right, height[i+1]);
            maxRight[i] = right;
        }

        for (int i = 0; i < height.size(); i++)
        {
            temp = (min(maxLeft[i], maxRight[i]) - height[i]);
            if(temp>0) {
                water += temp;
            }
        }
        return water;
    }

public:
    /*
    why does this work? not enough time to think about it.
    also apparently temp cannot be negative, but didn't think too much about it.
    */  
    int trapTwoPoint(vector<int> &height) {
        int left = 0, right = height.size()-1, maxLeft = height[0], maxRight = height.back();
        int temp = 0, water = 0;
        while(left<right) {
            if(maxLeft>maxRight) {
                temp = min(maxRight, maxLeft);
                temp = temp-height[right];
                if(temp>0) {
                    water+=temp;
                }
                maxRight = max(maxRight, height[right]);
                right--;
            } else {
                temp = min(maxRight, maxLeft);
                temp = temp-height[left];
                if(temp>0) {
                    water+=temp;
                }
                maxLeft = max(maxLeft, height[left]);
                left++;
            }
        }
        return water;
    }

};

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int water = 0;
    Solution sol;
    water = sol.trapTwoPoint(height);
    cout << water << endl;
    return 0;
}