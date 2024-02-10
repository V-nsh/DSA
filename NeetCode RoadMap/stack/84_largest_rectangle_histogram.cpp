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

public:
    int largestRectangleAreaPrac(vector<int>& heights){
        if(heights.size()==1) {
            return heights[0];
        }
        int area = 0, width = 1, height = heights[0];
        vector<pair<int, int>> mono; // pair of <i, height[i]> to calculate width on the go. 
        // so the idea is, we do not calculate the area right away. We start pushing increasing values, if we see a smaller value we need to pop, but before that we calculate the max area.
        for (int i = 0; i < heights.size(); i++)
        {
            int curr = i;
            while(!mono.empty() && (heights[i] < mono.back().second)) {
                int start = mono.back().first;
                width = i - start;
                height = mono.back().second;
                area = max(area, height*width); // notice we are only calculating area of the elements we are going to pop.
                curr = start; // since we are moving back, our starting point will be where we insert the element we are popping.
                mono.pop_back();
            }
            mono.push_back({curr, heights[i]});
        }

        // now the monotonic stack will only have increasing elements so calculate while removing all elements from back.
        while(!mono.empty()) {
            width = heights.size() - mono.back().first;
            height = mono.back().second;
            area = max(area, height*width);
            mono.pop_back();
        }

        return area;
    }

};

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    Solution sol;

    cout << sol.largestRectangleAreaPrac(heights);

    return 0;
}