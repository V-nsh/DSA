#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    /*
    increasing stack.
    */
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) {
            return heights[0];
        }
        int area = 0, width = 1, height = heights[0];
        vector<pair<int, int>> mono_stack;
        // mono_stack.push_back({0, heights[0]});
        // only keep increasing items, if smaller pop the larger one
        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while(!mono_stack.empty() && (heights[i] < mono_stack.back().second)) {
                int curr = mono_stack.back().first;
                width = i-curr;
                height = mono_stack.back().second;
                area = max(area, height*width);

                mono_stack.pop_back();
                start = curr;
            }
            mono_stack.push_back({start, heights[i]});
        }

        while (!mono_stack.empty())
        {
            width = heights.size() - mono_stack.back().first;
            height = mono_stack.back().second;
            area = max(area, height*width);

            mono_stack.pop_back();
        }
        
        
        return area;
    }
};

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    Solution sol;

    cout << sol.largestRectangleArea(heights);

    return 0;
}