#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    // literally fibo
    int climbStairs(int n) {
        if(n==1) {
            return 1;
        }
        if(n==2) {
            return 2;
        }
        int one = 1;
        int two = 2;
        int three = 0;
        for (int i = 1; i < n-1; i++)
        {
            three = one+two;
            one = two;
            two = three;
        }
        return three;
    }

public:
    // recursive fibo, TLE
    int climbStairsRecurs(int n) {
        if(n==1) {
            return 1;
        }
        if(n==2) {
            return 2;
        }
        return climbStairsRecurs(n-1) + climbStairsRecurs(n-2);
    }

/*
    create a tree, start with step=0 then there are two possibilities, take 2 steps or take 1 step, and then 2 possibilities for each child
*/
public:
    int climbStairsTree(int n) {
        if (n==1)
        {
            return 1;
        }
        if (n==2)
        {
            return 2;
        }
        unordered_map<int, vector<int>> tree;
        vector<int> count = {0};

        for (int i = 0; i < n; i++)
        {
            tree[i] = {i+1, i+2};
        }
        dfs(count, 0, n, tree);

        return count[0];
    }
public:
    void dfs(vector<int>& count, int node, int n, unordered_map<int, vector<int>>& tree) {
        if(node == n){
            count[0]++;
            return;
        }

        vector<int> temp = tree[node];
        for(int currNode: temp) {
            dfs(count, currNode, n, tree);
        }
    }

/*DP solution, basically fibo but with an array*/
public:
    int climbStairsDP(int n) {
        if (n==1)
        {
            return 1;
        }
        if (n==2)
        {
            return 2;
        }
        vector<int> dp(n+1, 1);
        for(int i = n-2; i >= 0; i--) {
            dp[i] = dp[i+1] + dp[i+2];
        }
        for(int it : dp) {
            cout << it << " ";
        }
        cout << "\n";
        return dp[0];
    }
};

int main() {
    Solution sol;
    cout << sol.climbStairsDP(5);
    return 0;
}