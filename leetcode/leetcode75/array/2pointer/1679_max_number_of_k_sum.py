class Solution(object):
    # brute force
    def maxOperationsBrute(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count = 0
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i]+nums[j]==k:
                    count += 1
                    nums[i] = -1
                    nums[j] = -1
        return count
    
    def searchNeedle(self, needle, hay):
        for i in hay:
            if i==needle:
                return True
    def maxOperationsSearch(self, nums, k):
        count = 0
        for i in range(len(nums)):
            cand = nums[i]
            if self.searchNeedle(k-cand, nums):
                nums[i] = -1
                count +=1
        return count
    
    def maxOperations(self, nums, k):
        nums = sorted(nums)
        count, i, j = 0, 0, len(nums)-1
        while i < j:
            sum = nums[i]+nums[j]
            if sum == k:
                i+=1
                j-=1
                count+=1
            elif sum>k:
                j-=1
            else:
                i+=1
        return count
    
    # more efficient using hashmap
    def maxOperationsHash(self, nums, k):
        count = 0
        hash_map = dict.fromkeys(nums, 0)
        for i in range(len(nums)):
            cand = k - nums[i]
            if hash_map.get(cand):
                hash_map[cand] -= 1
                count += 1
            else:
                hash_map[nums[i]] += 1
        return count

if __name__=="__main__":
    nums = [1,2,3,4]
    k = 5
    sol = Solution()
    print(sol.maxOperationsHash(nums, k))