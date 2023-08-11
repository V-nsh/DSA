#include<vector>
#include<map>
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
// brute force
    int equalPairsBrute(vector<vector<int>>& grid) {
        // map<int, int> rows;
        // map<int, int> cols;
        int rows = grid.size()-1;
        int cols = grid[0].size()-1;
        int count = 0, sameSoFar = 0;

        for (int i = 0; i<=rows; i++) {
            for(int j  = 0; j<=cols; j++) {
                for (int k = 0; k <=cols ; k++)
                {
                    cout << grid[i][k] << " " << grid[k][j] << "\n";
                    if(grid[i][k] == grid[k][j]){
                        sameSoFar++;
                    } else {
                        break;
                    }
                }
                if (sameSoFar==cols+1)
                {
                    count++;
                }
                sameSoFar=0;
            }
        }
        return count;
    }

public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rowMap;
        // initiallize the row hashMap
        int n = grid.size(), count = 0;
        for(auto i : grid){
            rowMap[i]++;
        }

        // just for testing
        // for(auto i : rowMap) {
        //     vector<int> test = i.first;
        //     for(int j=0; j < test.size(); j++) {
        //         cout << test[j];
        //     }
        //     cout << " second: " << i.second << "\n";
        // }

        for(int j = 0; j<n;j++) {
            vector<int> temp;
            for (int k = 0; k < n; k++)
            {
                temp.push_back(grid[k][j]);
            }
            count += rowMap[temp];
            temp.clear();
        }

        return count;
    }

public:
    int equalPairsUnordered(vector<vector<int>>& grid) {
        unordered_map<string, int> rowMap;
        // apparently searching in unordered map is faster than map, but it can't take vector<int>
        // for(auto i: grid){
        //     stringstream res;
        //     copy(i.begin(), i.end(), ostream_iterator<int>(res, "_"));
        // }
    }

};

int main() {
    // vector<vector<int>> grid = {
    //     {3, 2, 1},
    //     {1, 7, 6},
    //     {2, 7, 7}
    // };
    vector<vector<int>> grid = {
        {3,1,2,2},
        {1,4,4,5},
        {2,4,2,2},
        {2,4,2,2}
    };
    Solution sol;
    
    cout << sol.equalPairs(grid);

    return 0;
}