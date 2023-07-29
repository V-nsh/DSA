class Solution(object):
    '''
    what I am thinking of is finding the sum of the entire array at first 
    then start subtracting from say left until the sum of subtracted elements and the total becomes equal
    '''
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        rightSum, leftSum = sum(nums), 0
        for i in range(0, len(nums)):
            rightSum -= nums[i]
            if rightSum == leftSum:
                return i
            leftSum += nums[i]
        return -1
    
if __name__=="__main__":
    # nums = [1,7,3,6,5,6]
    # nums = [1,2,3]
    nums = [2,1,-1]
    # nums = [1,2,-3]
    sol = Solution()
    print(sol.pivotIndex(nums))