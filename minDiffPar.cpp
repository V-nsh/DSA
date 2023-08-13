#include<algorithm>
#include<vector>

using namespace std;

int minDiff(vector<int> nums){
    if(nums.size()==1){
        return -1;
    }
    int n = nums.size();
    int minSofar = nums[0]-nums[1];

    if(nums.size()==2){
        return minSofar;
    }

    sort(nums.begin(), nums.end());

    for(int i = 1; i<nums.size()-1; i++){
        minSofar = min(minSofar, nums[i+1]-nums[i]);
    }

    return min(minSofar, nums[n]-nums[n-1]);
}