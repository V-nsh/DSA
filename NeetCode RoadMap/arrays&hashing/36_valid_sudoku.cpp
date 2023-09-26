#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    struct pairHash
    {
        size_t operator()(const pair<size_t, size_t> &p) const
        {
            return p.first * 10 + p.second;
        }
    };

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // each row and column must have a unique value
        /*
        to tackle the 3x3 matrix we can represent each 3x3 matrix as some key
        | 0,0  | 0,1  | 0,2  |
        |  1,0 | 1,1  | 1,2  |
        |  2,0 | 2,1  | 2,2  |
        each key like 0,0 is a 3x3 matrix, we can easily get this key by dividing the i,j value by 3, in first 3, 0/3=0, 1/3=0
        for next 3/3=1, 2/3=1 and finally 7/3=2 and so on.
        */
        unordered_map<pair<int, int>, vector<char>, pairHash> map;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                char current = board[i][j];
                if (current != '.')
                {
                    if ((find(map[{i, j}].begin(), map[{i, j}].end(), current) != map[{i, j}].end()) ||
                        (find(map[{j, i}].begin(), map[{j, i}].end(), current) != map[{j, i}].end()) ||
                        (find(map[{i / 3 + 10, j / 3 + 10}].begin(), map[{i / 3 + 10, j / 3 + 10}].end(), current) != map[{i / 3 + 10, j / 3 + 10}].end()))
                    {
                        return false;
                    }
                    else
                    {
                        map[{i, j}].push_back(current);
                        map[{j, i}].push_back(current);
                        map[{i / 3 + 10, j / 3 + 10}].push_back(current);
                        continue;
                    }
                }
            }
        }
        return true;
    }

public:
    bool isValidSudokuSet(vector<vector<char>> &board)
    {
        unordered_set<string> set;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                char current = board[i][j];
                if (current != '.')
                {
                    string rowKey = "r" + to_string(i) + current;
                    string colKey = "c" + to_string(j) + current;
                    string boxKey = "b" + to_string((i / 3) + 10) + to_string((j / 3) + 10) + current;
                    if (set.count(rowKey) || set.count(colKey) || set.count(boxKey))
                    {
                        return false;
                    }
                    set.insert(rowKey);
                    set.insert(colKey);
                    set.insert(boxKey);
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
        {'6', '.', '.', '1', '9', '1', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '1', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}; // false
    cout << sol.isValidSudoku(board) << endl;

    return 0;
}