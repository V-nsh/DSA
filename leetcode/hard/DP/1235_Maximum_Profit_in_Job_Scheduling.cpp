#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int jobSchedulingBrute(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int maxProfit = profit[0];

        for (int i = 0; i < startTime.size(); i++)
        {
            int currProfit = profit[i];
            for(int j = i+1; j < startTime.size(); j++) {
                if(startTime[j] >= endTime[i]) {
                    currProfit += profit[j];
                    maxProfit = max(maxProfit, currProfit);
                }
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};

    cout << sol.jobSchedulingBrute(startTime, endTime, profit) << endl;

    return 0;
}