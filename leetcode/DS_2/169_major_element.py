class Solution(object):
    def majorityElement(self, nums):
        majority = nums[0]
        count  = 1
        for i in range(1, len(nums)):
            if majority == nums[i]:
                count += 1
            elif(count == 0):
                majority = nums[i]
                count = 1
            else:
                count -= 1
        return majority
    
    def majorityElement2(self, nums):
        nums.sort()
        return nums[len(nums)//2]
    
if __name__ == "__main__":
    s = Solution()
    nums = [2,2,1,1,1,2,2]
    print(s.majorityElement3(nums))