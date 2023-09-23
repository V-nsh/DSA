#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(const vector<int> &numbers, int target)
    {
        int front = 0, back = numbers.size() - 1;
        // vector<int> res;
        while (front < back)
        {
            if (numbers[front] + numbers[back] == target)
            {
                // res.push_back(front+1);
                // res.push_back(back+1);
                return {front + 1, back + 1};
            }
            else if (numbers[front] + numbers[back] > target)
            {
                back--;
            }
            else
            {
                front++;
            }
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    vector<int> res;
    res = sol.twoSum(numbers, 9);

    for (int i : res)
    {
        cout << i << " ";
    }

    return 0;
}