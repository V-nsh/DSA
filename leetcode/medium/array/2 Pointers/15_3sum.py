class Solution(object):
    '''
    brute force:
    take the first element and find if you can find 2 other numbers whose sum is the same as that number
    '''
    def threeSumBrute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = set()
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                for k in range(j+1, len(nums)):
                    if nums[j]+nums[k]+nums[i]==0:
                        res.add(tuple(sorted([nums[i], nums[j], nums[k]])))
        return list(res)
    
    '''
    if we consider -nums[i] as target we need to find two numbers whose sum equal -nums[i]
    '''
    def threeSumDuplicates(self, nums):
        res = []
        nums.sort()
        for i in range(len(nums)-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            target = -nums[i]
            hashMap = dict()
            for j in range(i+1, len(nums)):
                num2 = target - nums[j]
                if hashMap.get(num2):
                    res.append([nums[i], num2, nums[j]])
                while j<len(nums)-1 and nums[j]==nums[j+1]:
                    j+=1
                hashMap[nums[j]] = j
        return res
    
    def threeSum(self, nums):
        res = []
        nums = sorted(nums)
        print(nums)
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = -nums[i]
            left, right = i+1, len(nums)-1
            while left<right:
                sum = nums[left]+nums[right]
                if sum<target:
                    left+=1
                elif sum>target:
                    right-=1
                else:
                    part = [nums[i], nums[left], nums[right]]
                    res.append(part)
                    while (left<right and part[1]==nums[left]):
                        left += 1
                    while(left>right and part[2]==nums[right]):
                        right -= 1
            # while(i+1<len(nums) and nums[i+1]==nums[i]):
            #     i+=1
        return res
    
if __name__=="__main__":
    nums = [-1,0,1,2,-1,-4]
    # nums = [-2,0,0,2,2]
    sol = Solution()
    print(sol.threeSum(nums))