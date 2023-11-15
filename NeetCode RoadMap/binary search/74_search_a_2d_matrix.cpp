#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bot = matrix.size()-1;
        while (top<=bot)
        {
            int current = top + (bot-top) / 2;
            if(matrix[current][0] > target) {
                bot = current - 1;
            } else if (matrix[current][matrix[current].size()-1] < target) {
                top = current+1;
            } else {
                break;
            }
        }

        if(top > bot) {
            return false;
        }

        int right = matrix[0].size()-1, left = 0, current = top + (bot-top)/2;

        while(left <= right) {
            int mid = left + (right-left)/2;
            if(target > matrix[current][mid]) {
                left = mid+1;
            } else if (target < matrix[current][mid]) {
                right = mid-1;
            } else {
                return true;
            }
        }

        return false;
        
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,3,5,7}, {10,11,16,20}, {23,30,34,60}
    };
    int target = 9;
    Solution sol;

    cout << sol.searchMatrix(matrix, target) << endl;
    
    return 0;
}