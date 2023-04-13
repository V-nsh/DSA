#include<iostream>
#include<vector>

using namespace std;

// it is guaranteed that we will have a solution if the total difference is positive.
// so if that satisfies, we check further untel we find a positive difference between gas and cost. Because a negative difference will never be able to start to being with.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, start = 0, total = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            total += gas[i] - cost[i];
        }

        if (total < 0)
        {
            return -1;
        }
        
        total = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            total += gas[i] - cost[i];
            if (total < 0)
            {
                start = i+1;
                total = 0;
            }   
            
        }

        return start;
        
    }
};