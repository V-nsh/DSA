class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        money, prev_money = 0, 0
        for num in nums:
            old_money = money
            money = max(money, prev_money+num)
            prev_money = old_money
        return money
    
if __name__=="__main__":
    nums = [1,2,3,1]
    s = Solution()
    print(s.rob(nums))