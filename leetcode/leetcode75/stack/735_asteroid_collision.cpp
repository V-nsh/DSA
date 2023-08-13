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
            if(current > 0 || res.empty()) {
                res.push_back(current);
            } else {
                while(!res.empty() && res.back()>0 && (res.back() < abs(current))) {
                    res.pop_back();
                }
                if (!res.empty() && res.back()== abs(current))
                {
                    res.pop_back();
                } else if (res.empty() || res.back() < 0) {
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