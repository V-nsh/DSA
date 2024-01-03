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

public:
    int carFleetStack(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() == 1)
        {
            return 1;
        }
        
        vector<pair<int, double>> map;
        vector<double> mono_stack;
        double currTime = 0.0;

        for(int i=0; i<position.size(); i++) {
            map.push_back({position[i], (target-position[i]) / (double)speed[i]});
        }
        sort(map.begin(), map.end(), greater<pair<int,double>>());
        mono_stack.push_back(map[0].second);

        for (int i = 1; i < position.size(); i++)
        {
            currTime = map[i].second;
            if (currTime > mono_stack.back())
            {
                mono_stack.push_back(currTime);
            }
        }
        return mono_stack.size();
    }

};

int main() {
    // int target = 12;
    // vector<int> position = {10,8,0,5,3};
    // vector<int> speed = {2,4,1,1,3};
    // int target = 10;
    // vector<int> position = {6,8};
    // vector<int> speed = {2,3};
    int target = 17;
    vector<int> position = {8,12,16,11,7};
    vector<int> speed = {6,9,10,9,7};
    Solution sol;
    int ans = sol.carFleetStack(target, position, speed);
    cout << ans << endl;

    return 0;
}