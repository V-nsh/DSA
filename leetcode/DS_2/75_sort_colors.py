# this is just a sorting problem, but the trick is to use 3 pointers

class Solution(object):
    # bucket sort is a possible solution for this, use a hashmap to keep track of the counts
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        hash = {}
        for i in nums:
            if i not in hash:
                hash[i] = 1
            else:
                hash[i] += 1
        j = 0
        for i in range(0, 3):
            if i in hash:
                for k in range(hash[i]):
                    nums[j] = i
                    j+=1

    # 3 pointer approach
    def sortColors2(self, nums):
        l, r, = 0, len(nums)-1
        i = 0 # this is the pointer that moves through the array, we don't increment this when we swap 2 because we might swap 2 for 0 and end up with something like [0, 1, 0, 1, 2, 2]
        while i <= r:
            if nums[i] == 0:
                nums[i], nums[l] = nums[l], nums[i]
                l+=1
                i+=1
            elif nums[i] == 2:
                nums[i], nums[r] = nums[r], nums[i]
                r -= 1
            else:
                i+=1

if __name__ == "__main__":
    s = Solution()
    nums = [2,0,2,1,1,0]
    # nums = [2,0]
    s.sortColors2(nums)
    print(nums)