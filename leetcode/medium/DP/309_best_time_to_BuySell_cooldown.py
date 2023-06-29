class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        T_i0, T_i1 = 0, -prices[0]
        T_i0_pre = 0
        for price in prices:
            T_i0_old = T_i0
            T_i0 = max(T_i0, T_i1+price)
            # the pre variable will skip one value
            # we cannot use the profit i.e T_i0 from previous day so we need to keep a track of the older day
            T_i1 = max(T_i1, T_i0_pre-price)
            T_i0_pre = T_i0_old
        return T_i0

if __name__=='__main__':
    s = Solution()
    # prices = [1,2,3,0,2]
    prices = [2,1,4]
    print(s.maxProfit(prices))