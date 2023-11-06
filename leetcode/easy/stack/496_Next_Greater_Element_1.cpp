#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElementBrute(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> map;
        /*
        create a lookup table sort of thing with the map, if the element doesn't exist in the table we skip from nums2.
        the idea is to see if the elemnt in nums2 is present in nums1, if so find the next greatest element or just skip to next interation.
        */
        for(int i=0; i<nums1.size(); i++) {
            map[nums1[i]] = i;
        }

        for(int j = 0; j<nums2.size(); j++) {
            if(map.find(nums2[j]) == map.end()) {
                continue;
            }
            for(int k = j+1; k<nums2.size(); k++) {
                if(nums2[k] > nums2[j]) {
                    int place = map[nums2[j]];
                    ans[place] = nums2[k];
                    break;
                }
            }
        }

        return ans;
    }

public:
    /*
    the idea is simple, we get a monotonic decreasing stack, if the incoming element is greater than stack.top() we start popping until we find greater element
    or the stack is empty. if the incoming element is greater we see if the top element is present in nums2 since the incoming element is the next greater element after the top.
    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        vector<int> mono_stack;
        unordered_map<int, int> map;
        for (int i = 0; i < nums1.size(); i++)
        {
            map[nums1[i]] = i;
        }
        
        mono_stack.push_back(nums2.front());

        for (int i = 1; i < nums2.size(); i++)
        {
            if(mono_stack.back() < nums2[i]) {
                while(!mono_stack.empty() && mono_stack.back() < nums2[i]) {
                    if(!(map.find(mono_stack.back()) == map.end())) {
                        ans[map[mono_stack.back()]] = nums2[i];
                    }
                    mono_stack.pop_back();
                }
            }
            mono_stack.push_back(nums2[i]);
        }

        return ans;
        
    }

};

int main() {
    // vector<int> nums1 = {4,1,2};
    // vector<int> nums2 = {1,3,4,2};
    vector<int> nums1 = {1,3,5,2,4};
    vector<int> nums2 = {6,5,4,3,2,1,7};
    vector<int> ans;
    Solution sol;
    ans = sol.nextGreaterElement(nums1, nums2);

    for(int num : ans) {
        cout << num << " ";
    }

    return 0;
}