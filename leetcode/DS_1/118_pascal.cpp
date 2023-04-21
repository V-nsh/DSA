#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);
            pascal.push_back(row);
            for (int j = 0; j <= i; j++)
            {
                if (i >= 1 && j >= 1 && j < pascal[i - 1].size())
                {
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
                }
            }
        }
        return pascal;
    }
};