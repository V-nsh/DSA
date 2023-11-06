#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperaturesBruteTLE(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        for(int i = temperatures.size()-2; i>=0; i--) {
            if(temperatures[i] < temperatures[i+1]) { // if the next element is greater it will only take 1 day.
                res[i] = 1;
            } else {
                for(int j = i; j <temperatures.size(); j++) {
                    if(temperatures[j] > temperatures[i]) { // or we find the next greatest element from current element, O(N^2) time.
                        res[i] = j-i;
                        break;
                    }
                }
            }
        }
        return res;
    }

public:
    /*
    solve 496 next greater element first first.
    we only keep decreasing monotonic stack, and store the index of the decreasing elements. the distance from next greatest element to current can be found by i-idx of the smaller element.
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        vector<int> mono_stack;
        mono_stack.push_back(0);

        for (int i = 0; i < temperatures.size(); i++)
        {
                while(!mono_stack.empty() && (temperatures[i] > temperatures[mono_stack.back()])) {
                    int ptr = mono_stack.back(); //element at this positon is just smaller than the current ith element.
                    res[ptr] = i-ptr;
                    mono_stack.pop_back();
                }
            mono_stack.push_back(i);
        }
        return res;
    }

};

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution sol;
    vector<int> res;
    res = sol.dailyTemperatures(temperatures);
    for(int r : res) {
        cout << r << " ";
    }

    return 0;
}