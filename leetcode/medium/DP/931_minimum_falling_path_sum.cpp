#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minFallingPathSumBrute(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minSum = INT_MAX;
        vector<vector<int>> cache(n+1, vector<int>(matrix[0].size()+1, INT_MAX));
        // unordered_map<int, vector<int>> cache;
        for(int i = 1; i < n; i++) {
            int pathSum = recurse(matrix, cache, 0, i);
            minSum = min(minSum, pathSum);
        }

        return minSum;
    }

private:
    int findVal(unordered_map<int, vector<int>>& cache, const vector<int>& target) {
        for (const auto& pair : cache) {
            if (pair.second == target) {
                return pair.first;
            }
        }
        return 0;
    }

public:
    int recurse(vector<vector<int>>& matrix, vector<vector<int>>& cache, int row, int col) {
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }
        if (col < 0 || col == matrix[0].size()) {
            return INT_MAX;
        }

        // vector<int> currentVector = {row, col};

        // int found = findVal(cache, currentVector);

        // if (found) {
        //     cout << "Found in cache: " << found << " for position (" << row << ", " << col << ")" << endl;
        //     return found+matrix[row][col];
        // }

        if(cache[row][col] != INT_MAX) {
            return cache[row][col];
        }

        int left = recurse(matrix, cache, row + 1, col - 1);
        int right = recurse(matrix, cache, row + 1, col + 1);
        int below = recurse(matrix, cache, row + 1, col);

        int currSum = matrix[row][col] + min({left, right, below});
        // cache[currSum] = currentVector;

        return currSum;
    }

public:
    /*
    the idea is to just build the solution from bottom, we add the lowest element from right, left and mid to the current element,
    look at last row from the second last row and find the minimum element connected to it.
    */
    int minFallingPathSumTabulation(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 1) {
            return *min_element(matrix[0].begin(), matrix[0].end());
        }
        int cols = matrix[0].size();

        for(int i = rows-2; i >= 0 ; i--) {
            for(int j = 0; j < cols; j++) {
                int mid = matrix[i+1][j];
                int left = j > 0 ? matrix[i+1][j-1] : INT_MAX;
                int right = j < cols-1 ? matrix[i+1][j+1] : INT_MAX;
                matrix[i][j] += min({mid, left, right});
            }
        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    int result = sol.minFallingPathSumTabulation(matrix);
    
    cout << "Minimum Falling Path Sum: " << result << endl;
    return 0;
}