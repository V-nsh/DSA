#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int rows = matrix.size()-1;
    int cols = matrix[rows].size()-1;
    for(int i=1; i<matrix.size(); i++) {
        for(int j = 0; j<matrix[i].size(); j++) {
            if(j==0){
                matrix[i][j] = max(matrix[i][j]+matrix[i-1][j], matrix[i][j]+matrix[i-1][j+1]);
            } else if (j==matrix[i].size()) {
                matrix[i][j] = max(matrix[i][j]+matrix[i-1][j], matrix[i][j]+matrix[i-1][j-1]);
            } else {
            matrix[i][j] = max(matrix[i][j]+matrix[i-1][j], max(matrix[i][j]+matrix[i-1][j-1], matrix[i][j]+matrix[i-1][j+1]));
            }
        }
    }

    // for (const auto& row : matrix) {
    //     for (int value : row) {
    //         std::cout << value << " ";
    //     }
    //     std::cout << std::endl;
    // }

    int max = *max_element(matrix[cols].begin(), matrix[cols].end());

    return max;
}

int main(){
    vector<vector<int>> matrix;
    matrix = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };

    cout << getMaxPathSum(matrix);

    return 0;
}