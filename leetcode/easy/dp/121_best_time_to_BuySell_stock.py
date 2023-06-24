import sys

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems/
        T = [[0 for _ in range(2)] for _ in range(len(prices))]
        # we will only take care of i that is the day and 0 and 1 that is the state since k is constant for this problem, we can either buy or sell on a given day
        # note that 0 means we sold the stock at the end of the day and 1 means we bought the stock at the end of the day
        for i in range(len(prices)):
            # base case
            if i == 0:
                T[i][0] = 0
                T[i][1] = -prices[i]
                continue
            # recurrence relation
            # if we sold the stock at the end of the day, we can either sell it today or sell it yesterday. 
            T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])
            # if we bought the stock at the end of the day, we can either buy it today or buy it yesterday.
            # that is keep yesterday's state or buy it today
            # note that we are not subtracting the price from previous transaction because we can only buy once.
            # see how we initialize for 0th day 
            '''
            if we would be able to buy only once we don't subtract because -price will simply give the cost to buy, 
            when selling that is going to state 0 we add the price again, which will be the selling price.
            '''
            T[i][1] = max(T[i-1][1],-prices[i])
        print(T)
        return T[len(prices)-1][0]
    
    # optimized
    def maxProfitOptimized(self, prices):
        T_i0, T_i1 = -sys.maxsize, -prices[0]

        for price in prices:
            T_i0 = max(T_i0, T_i1+price)
            T_i1 = max(T_i1, -price)
        return T_i0
if __name__=="__main__":
    s = Solution()
    prices = [7,1,5,3,6,4]
    # prices = [7,6,4,3,1]
    print(s.maxProfitOptimized(prices))