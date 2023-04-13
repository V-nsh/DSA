// #include<iostream>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<int>> ins(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = 0, end = 0;
        // vector<int>:: iterator i1, i2;
        for (int i = 0; i < intervals.size()-1; i++)
        {
            for (int j = 0; j < 1; j++)
            {
                if (intervals[i][0] < newInterval[0])
                {
                    start = i;
                }
                
                if (intervals[i][1] >newInterval[1])
                {
                    end = i;
                }
            }
        }

        intervals[start][1] = intervals[end][1];
        intervals.erase(intervals.begin()+start+1, intervals.begin()+end); 

        cout << start << "\n";
        cout << end;

        return intervals;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals;
    vector<vector<int>> ans;
    intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval;
    newInterval = {4,8};

    ans = sol.ins(intervals, newInterval);
    cout << "\n";
    for (int i = 0; i < intervals.size()-1; i++)
    {
        cout << ans[i];
    }
    
    return 0;
}