#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> difs;
        int days = 0;

        for (auto i: tasks)
        {
            ++difs[i];
        }

        for (auto itr = difs.begin(); itr != difs.end(); itr++)
        {
            if (itr->second == 1)
            {
                return -1;
            }
            if (itr->second%3==0)
            {
                days += itr->second%3;
            } else {
                days += itr->second%3+1;
            }
            
        }
        
        return days;
    }
};