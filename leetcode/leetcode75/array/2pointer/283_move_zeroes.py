class Solution(object):
    # one way would be to swap with the next element if 0.
    def moveZeroesBrute(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        j = len(nums)
        for i in range(j-1):
            for i in range(j-1):
                if nums[i]==0:
                    nums[i], nums[i+1] = nums[i+1], nums[i]
        print(nums)
    
    # another solution would be to keep a track of non zero, place them after one another and fill the remaining elements with 0
    def moveZeroes(self, nums):
        cur = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[cur] = nums[i]
                cur += 1
        for i in range(cur, len(nums)):
            nums[i] = 0

        print(nums)
    
    # the above approach still not the optimum, think of a case where the array is [00000 .... 1]
    '''
        we will check each 0, then again run cur-len(nums) i.e. for this case len-1 times, not cool..

        instead we can straight up put a 0 at the fast pointer and fill the current pointer with the non 0 element
    '''
    def moveZeroesOpt(self, nums):
        cur = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[cur], nums[i] = nums[i], nums[cur]
                cur+=1

        print(nums)
if __name__=="__main__":
    nums = [0,1,0,3,12]
    # nums = [0]
    # nums = [0, 0, 0, 0, 0, 1]
    s = Solution()
    s.moveZeroesOpt(nums)