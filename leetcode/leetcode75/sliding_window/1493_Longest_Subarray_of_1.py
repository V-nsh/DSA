class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, zeroSoFar, maxLength = 0, 0, 0
        for right in range(len(nums)):
            if nums[right]==0:
                zeroSoFar+=1
            while zeroSoFar>1:
                if nums[left]==0:
                    zeroSoFar -= 1
                left+=1
            maxLength = max(maxLength, right-left+1)
        return maxLength-1
    
if __name__=="__main__":
    # nums = [1,1,0,1]
    # nums = [0,1,1,1,0,1,1,0,1]
    nums = [1,1,1]
    sol = Solution()
    print(sol.longestSubarray(nums))