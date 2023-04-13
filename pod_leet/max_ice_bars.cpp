#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int creams = 0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++)
        {
            if (costs[i] > coins)
            {
                break;
            }
            coins -= costs[i];
            creams++;
        }
        return creams;
    }
};