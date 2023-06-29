class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        T_i0, T_i1 = 0, -prices[0]

        for price in prices:
            # we can either subtract the fee while selling or buying since they come as a pair
            # here I choose while selling because it is more intuitive
            T_i0_old = T_i0
            # I haven't used the T_i0_old in case 2 but this is the correct way
            # without using the old value it means we are buying and selling on the same day
            T_i0 = max(T_i0, T_i1+price -fee)
            T_i1 = max(T_i1, T_i0_old-price)
        return T_i0
    
if __name__=='__main__':
    prices = [1,3,2,8,4,9] 
    fee = 2
    # prices = [1,3,7,5,10,3]
    # fee = 3
    s = Solution()
    print(s.maxProfit(prices, fee))

# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems/