class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        # greedy approach won't work
        # say we have an array [1, 3, 4, 5] and target = 7
        # we might think of sorting the array and then start from the largest number
        # this approach will give us 5 + 1 + 1 = 7, but 3 coins is the optimal solution, best solution is 2, i.e 3 + 4.

        # brute force: try all possible combinations
        # we can use recursion to try all possible combinations, DFS - backtracking
        '''
                                  amount = 7
                                1/   3|   4\  5\
                                6     4     3  2
                                                1/3|4\5\
                                                 1  -1  thus we can prune the next part as  numbers get bigger
                                                1|
                                                0
                                        
        '''

    # some inaccuracy in this approach
    def dfsApproach(self, coins, amount):
        if amount == 0:
            return 0
        if len(coins) ==  1:
            if amount % coins[0] == 0:
                return amount//coins[0]
            else:
                return -1
        def dfs(coins, amount, index, count):
            if amount == 0:
                return count
            if index >= len(coins):
                return -1
            if coins[index] > amount:
                return dfs(coins, amount, index+1, count)
            else:
                return min(dfs(coins, amount-coins[index], index, count+1), dfs(coins, amount, index+1, count))
        return dfs(coins, amount, 0, 0)
    
    # correct but TLE
    def dfsCoinChange(self, coins, amount):
        def dfs(amount, index, count):
            if amount == 0:
                return count
            if index >= len(coins) or amount < 0:
                return -1
            min_count  =  float('inf')

            for i in range(amount//coins[index]+1):
                remaining = amount - i*coins[index]
                res =  dfs(remaining, index+1, count+i)
                if res != -1:
                    min_count = min(min_count, res)
            return min_count if min_count != float('inf') else -1
        return dfs(amount, 0, 0)
    
    # best solution is to use DP-Bottom up approach.
    # we first find the the number of coins we need to reach from 0->target.
    # store it in a table DP. then we can easily find DP[target]
    # eg: coins = [1, 3, 4, 5] target = 7
    # DP = [0, 1, 2, 1, 1, 1, 2], i.e. DP[0] = 0, DP[1] = 1, DP[2] = 2
    # thus for DP[7] =  lets start with 1 i.e coins[0]
    # DP[7] = 1 + DP[6] = 1 + 2 = 3
    # DP[7] = 1 + DP[4] = 1 + 1 = 2

    def coinChange(self, coins, amount):
        dp = [float('inf') for _ in range(amount+1)]
        dp[0] = 0
        for i in range(1, amount+1):
            for c in coins:
                if i >= c:
                    dp[i] = min(dp[i], dp[i-c]+1)
        return dp[amount] if dp[amount] != float('inf') else -1
if __name__ == "__main__":
    s = Solution()
    # coins = [1, 2, 5]
    coins = [1, 3, 4, 5]
    # amount = 11
    amount = 7
    print(s.coinChange(coins, amount))