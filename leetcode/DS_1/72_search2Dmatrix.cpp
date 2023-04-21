#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = 0;
        int col = matrix[rows].size() - 1;
        int row = matrix.size();

        while (rows < row && col > -1)
        {
            if (matrix[rows][col] == target)
            {
                return true;
            }

            if (matrix[rows][col] < target)
            {
                rows++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};