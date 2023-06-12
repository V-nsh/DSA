class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if not nums:
            return []
        
        res = []
        start = nums[0]
        end = nums[0]
        for i in range(1, len(nums)):
            if nums[i] == end + 1:
                end += 1
            else:
                if start == end:
                    res.append(str(start))
                else:
                    res.append(str(start) + "->" + str(end))
                start = nums[i]
                end = nums[i]
        if start == end:
            res.append(str(start))
        else:
            res.append(str(start) + "->" + str(end))
        return res
    

if __name__ == '__main__':
    nums = [0,1,2,4,5,7]
    print(Solution().summaryRanges(nums))