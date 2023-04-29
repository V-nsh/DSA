class Solution(object):
    def singleNumber(self, nums):
        dic = {}
        for i in nums:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] =1
        for i in dic:
            if dic[i] == 1:
                return i
        return None
    
    # another approach could be to sort the array and then check if the number is equal to the next number
    def singleNumber2(self, nums):
        nums.sort()
        for i in range(0, len(nums)-1, 2):
            if nums[i] != nums[i+1]:
                return nums[i]
        return nums[-1]
    
    # another approach could be to use XOR
    def singleNumber3(self, nums):
        a = 0
        for i in nums:
            a ^= i
        return a
    
    # another approach could be to use set
    def singleNumber4(self, nums):
        return 2 * sum(set(nums)) - sum(nums)

if __name__ == "__main__":
    s = Solution()
    nums = [4,1,2,1,2]
    print(s.singleNumber(nums))
    print(s.singleNumber2(nums))
    print(s.singleNumber3(nums))
    print(s.singleNumber4(nums))