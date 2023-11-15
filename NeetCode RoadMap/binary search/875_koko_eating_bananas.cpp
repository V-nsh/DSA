#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

class Solution {
public:
    /*
    the idea is to binary search from 1 to max element in the piles array and find the total hours that would require for current element (i.e the mid since we are doing binary)
    if the hours is less than maximum allowed i.e h, then we can try and go for even smaller value of k
    else we need to increase the k value since we need to finish bananas faster.
    */
    int minEatingSpeed(vector<int>& piles, int h) {
        auto maxEl = *max_element(piles.begin(), piles.end());
        long long left = 1, mid = 0, minK = maxEl;

        while(left <= maxEl) {
            mid = left + (maxEl-left)/2;
            long long hours = 0;
            for(int it: piles) {
                hours += ceil(it/(double)mid);
            }
            if(hours <= h) {
                minK = min(minK, mid);
                maxEl = mid-1;
            } else {
                left = mid+1;
            }
        }
        return minK;
    }
};

int main() {
    vector<int> piles = {312884470};
    int h = 312884469;
    Solution sol;
    cout << sol.minEatingSpeed(piles, h);
    return 0;
}