#include<vector>
int __INT_MAX__ = 2147483647;

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leastCP = __INT_MAX__;
        int profit = 0;
        int profit_today = 0;
        int i = 0;

        for (i; i < prices.size(); i++)
        {
            if (prices[i] < leastCP)
            {
                leastCP = prices[i];
            }

            profit_today = prices[i] - leastCP;

            if (profit < profit_today)
            {
                profit = profit_today;
            }
        }
        return profit;
    }
};