import sys

# class Solution(object):
#     def maxProfit(self, k, prices):
#         """
#         :type k: int
#         :type prices: List[int]
#         :rtype: int
#         """
#         # if k that is allowed transactions is more than len/2 then we extend k to positive infinity, that is there is no limit on the number of transactions allowed
#         if k >=  len(prices)//2:
#             T_ik0, T_ik1 = -sys.maxsize, -sys.maxsize

#             for price in prices:
#                 T_ik0 = max(T_ik0, T_ik1+price)
#                 T_ik1 = max(T_ik1, T_ik0-price)
#             return T_ik0
#         T_ik0 = [0]*k
#         T_ik1 = [-sys.maxsize]*k

#         for price in prices:
#             for j in reversed(range(0, k)):
#                 T_ik0[j] = max(T_ik0[j], T_ik1[j]+price)
#                 T_ik1[j] = max(T_ik1[j], T_ik0[j-1]-price)
#         return T_ik0[k-1]

# chatgpt
class Solution(object):
    def maxProfit(self, k, prices):
        if not prices:
            return 0

        if k >= len(prices) // 2:
            # If k is large enough, it becomes a problem of unlimited transactions
            # We can use a simple greedy approach to find the maximum profit
            max_profit = 0
            for i in range(1, len(prices)):
                if prices[i] > prices[i - 1]:
                    max_profit += prices[i] - prices[i - 1]
            return max_profit

        # Use dynamic programming to solve the problem
        # Create two arrays to store the maximum profit at each transaction and each day
        # T[i][j] represents the maximum profit with at most i transactions on day j
        T = [[0] * len(prices) for _ in range(k + 1)]

        for i in range(1, k + 1):
            max_diff = -prices[0]
            for j in range(1, len(prices)):
                T[i][j] = max(T[i][j - 1], prices[j] + max_diff)
                max_diff = max(max_diff, T[i - 1][j] - prices[j])

        return T[k][len(prices) - 1]


if __name__=='__main__':
    s = Solution()
    k = 2
    prices = [2,4,1]
    print(s.maxProfit(k, prices))