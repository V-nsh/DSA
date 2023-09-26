#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    struct pairHash
    {
        size_t operator()(const pair<size_t, size_t> &p) const
        {
            return p.first ^ p.second;
        }
    };

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<pair<int, int>, vector<int>, pairHash> map;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                char current = board[i][j];
                if ((find(map[{i, j}].begin(), map[{i, j}].end(), current) == map[{i, j}].end()) ||
                    (find(map[{j, i}].begin(), map[{j, i}].end(), current) == map[{j, i}].end()) ||
                    (find(map[{i / 3, j / 3}].begin(), map[{i / 3, j / 3}].end(), current) == map[{j / 3, i / 3}].end()))
                {
                    return false;
                }
                else
                {
                    map[{i, j}].push_back(current);
                    map[{j, i}].push_back(current);
                    map[{i / 3, j / 3}].push_back(current);
                    continue;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << sol.isValidSudoku(board) << endl;

    return 0;
}