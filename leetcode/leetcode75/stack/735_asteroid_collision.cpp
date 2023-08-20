#include<vector>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        if (n==2 && (asteroids[0] == -asteroids[1]))
        {
            return {};
        }

        for (int i = n-1; i > 0; i--)
        {
            if (asteroids[i] < 0 && asteroids[i-1]>0)
            {
                if (-asteroids[i] < asteroids[i-1])
                {
                    asteroids.pop_back();
                } else if (-asteroids[i] == asteroids[i-1]) {
                    asteroids.pop_back();
                    asteroids.pop_back();
                } else {
                    vector<int>::iterator it = asteroids.begin();
                    asteroids.erase(it+i-1);
                }
                
            }
            
        }
        

        for (auto j: asteroids) {
            cout << j << " ";
        }

        return asteroids;
    }

    // kinda brute
public:
    vector<int> asteroidCollisionBrut(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> res;
        // res.push_back(asteroids[0]);
        for (int i = 0; i < n; i++)
        {
            // if (res.back() > 0 && asteroids[i] < 0)
            // {
            //     while(!res.empty() && res.back()>0 && (res.back() < abs(asteroids[i]))) {
            //         res.pop_back();
            //     }

            //     if(!res.empty() && res.back()==abs(asteroids[i])) {
            //         res.pop_back();
            //     } 
            //     // else if (res.empty() || res.back() < 0) {
            //     //     res.push_back(asteroids[i]);
            //     // }            
            // } else {
            //     res.push_back(asteroids[i]);
            // }

            int current = asteroids[i];
            // if the incoming asteroid is moving in positive direction it's going right, thus it won't crash with anything, so push.
            if(current > 0 || res.empty()) {
                res.push_back(current);
            } else {
                //otherwise the incoming asteroid is negative
                // if it's negative we need to check if the previous one was positive and the incoming asteroid is greater than the last one
                // we pop or destroy the last asteroid until the condition holds.
                while(!res.empty() && res.back()>0 && (res.back() < abs(current))) { 
                    res.pop_back();
                }
                // if equal both asteroids destroy each other
                if (!res.empty() && res.back()== abs(current))
                {
                    res.pop_back();
                } 
                // else there are no asteroids or the one before it is also moving in the left, ie negative direction.
                else if (res.empty() || res.back() < 0) {
                    res.push_back(current);
                }
            }
            
        }

        // for(auto it: res) {
        //     cout << it << " ";
        // }
        

        return res;
    }
};

int main() {
    Solution sol;
    // vector<int> aster  = {-2,-1,1,2};
    // vector<int> aster = {-2,-2,1,-1};
    // vector<int> aster = {-2,-2,1,-2};
    vector<int> aster = {-2,1,-1,-2};
    sol.asteroidCollisionBrut(aster);
    return 0;
}