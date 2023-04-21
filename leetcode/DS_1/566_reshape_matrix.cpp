#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        size_t size = 0;
        int resRow = 0;
        int resCol = 0;
        vector<vector<int>> result(r, vector<int>(c));

        for (auto V : mat)
        {
            size += V.size();
        }

        if ((r * c) != size)
        {
            return mat;
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (resCol == c)
                {
                    resRow++;
                    resCol = 0;
                }
                result[resRow][resCol] = mat[i][j];
                resCol++;
            }
        }

        return result;
    }
};