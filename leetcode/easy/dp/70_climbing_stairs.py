from collections import defaultdict

class Solution(object):
    # brute force
    # TLE
    def climbStairsBrute(self, n):
        """
        :type n: int
        :rtype: int
        """
        # create a tree and then traverse it to so how many paths lead to n
        tree = defaultdict(list)
        count = [0]
        for i in range(n):
            tree[i].append(i+1)
            tree[i].append(i+2)
        print(tree)
        self.dfs(0, tree, count, n)
        return count[0]
    def dfs(self, node, tree, count, n):
        if node==n:
            count[0] += 1
            return
        for i in tree[node]:
            self.dfs(i, tree, count, n)

    # DP
    # we are solving similar problems again and again, see the print of above tree and draw it
    # if we already have 2 we don't need to do a complete DFS and calculation, similarly for 3 as well
    # we first start with finding the bottom-most element and work our way up
    # this is called bottom up DP
    # therefore to reach n from DP[n]  there is only 1 way, thus DP[n] = 1 also from n-1 only possible way to reach n is 1
    # thus DP[n-1] = 1
    def climbStairs(self, n):
        dp = [1]*(n+1)
        for i in reversed(range(0, n-1)):
            dp[i] = dp[i+1]+dp[i+2]
        return max(dp)
    
    # optimized space
    # we are basically adding the last two numbers to itself
    # thus switching the second number to newly added one would make sense
    # somehow this says it only beats 10% while the one above beats 90, weird.
    def climbingStairsOptimized(self, n):
        first, second = 1, 1
        for i in range(0, n-1):
            temp = second
            second = first+second
            first = temp
        return second
    
if __name__=='__main__':
    n = 5
    s = Solution()
    # print(s.climbStairsBrute(n))
    print(s.climbingStairsOptimized(n))