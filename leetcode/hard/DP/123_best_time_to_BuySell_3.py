import sys

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # even check leetcode\easy\dp\121_best_time_to_BuySell_stock.py
        # https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems/
        # here we are allowed to do only 2 transactions so we need to keep in mind the ith day, no of transactions and if we have or don't have the stock at the end of the day
        # T_i20 on ith day if we have 2 transactions left with no stocks in hand
        # T_i21 on ith day if we have 2 transactions left with 1 stock in hand
        # T_i10 on ith day if we have 1 transaction left with no stocks in hand
        # T_i11 on ith day if we have 1 transaction left with 1 stock in hand
        T_i20, T_i10 = 0, 0
        T_i21, T_i11 = -sys.maxsize, -sys.maxsize

        for price in prices:
            T_i20 = max(T_i20, T_i21+price)
            T_i21 = max(T_i21, T_i10-price)
            T_i10 = max(T_i10, T_i11+price)
            T_i11 = max(T_i11, -price)

        return T_i20
    
if __name__=="__main__":
    s = Solution()
    prices = [3,3,5,0,0,3,1,4]
    print(s.maxProfit(prices))