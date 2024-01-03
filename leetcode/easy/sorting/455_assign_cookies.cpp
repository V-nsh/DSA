#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    /*
        Just sort and compare, we are asked to find how many kids can get a cookie. if the size is greater or equal to the greed of the kid we give the cookie to the kid. 
    */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0, i = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (i< g.size() && j<s.size())
        {
            if(s[j] >= g[i]) {
                count++;
                i++;
            }
            j++;
        }
        

        return count;        
    }
};