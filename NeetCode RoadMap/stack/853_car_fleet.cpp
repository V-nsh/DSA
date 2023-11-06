#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    /*
    the basic idea is to sort the car based on who's closest to target, then find the time they would take to reach it.
    if first car takes 3s and second takes 2s, than the second one has to slow down and form a fleet with first, 
    but if third takes 5s that's another fleet since it's not fast enough to catch up with 3s car speed.

    stack implementation is the same thing, in comparison instead of having a fleet variable we keep a stack and only push those elements that have time
    greater than the one at top.
    */
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> map;
        int fleet = 0;
        double currTime = 0.0, maxTime = 0.0;
        for(int i = 0; i < position.size(); i++) {
            map[position[i]] = speed[i];
        }
        sort(position.begin(), position.end(), greater<int>());

        for(int i = 0; i< map.size(); i++) {
            currTime = (target - position[i]) / (double)map[position[i]];
            if(currTime> maxTime) {
                fleet++;
                maxTime = currTime;
            }
        }
        return fleet;
    }
};

int main() {
    // int target = 12;
    // vector<int> position = {10,8,0,5,3};
    // vector<int> speed = {2,4,1,1,3};
    int target = 10;
    vector<int> position = {6,8};
    vector<int> speed = {2,3};
    Solution sol;
    int ans = sol.carFleet(target, position, speed);
    cout << ans << endl;

    return 0;
}