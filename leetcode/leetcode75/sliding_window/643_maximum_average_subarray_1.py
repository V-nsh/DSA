import sys

class Solution(object):
    # brute force
    def findMaxAverageBrute(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        # TLE ofc
        i, j= 0, k
        maxSofar = -sys.maxsize
        if len(nums)==1:
            return nums[0]
        for i in range(len(nums)):
            if j<=len(nums):
                total = sum(nums[i:j])/k
                maxSofar = max(maxSofar, total)
            j += 1
        return maxSofar
    
    def findMaxAverage(self, nums, k):
        if len(nums)==1:
            return nums[0]
        j = k
        total = sum(nums[:k])
        maxSoFar = total
        for j in range(k, len(nums)):
            total = (total+nums[j]-nums[j-k])
            maxSoFar = max(maxSoFar, total)
        return maxSoFar/ float(k)

if __name__ == "__main__":
    # nums = [1,12,-5,-6,50,3]
    # k = 4
    # nums = [5]
    # k=1
    # nums = [0,1,1,3,3]
    # k = 4
    # nums = [8860,-853,6534,4477,-4589,8646,-6155,-5577,-1656,-5779,-2619,-8604,-1358,-8009,4983,7063,3104,-1560,4080,2763,5616,-2375,2848,1394,-7173,-5225,-8244,-809,8025,-4072,-4391,-9579,1407,6700,2421,-6685,5481,-1732,-8892,-6645,3077,3287,-4149,8701,-4393,-9070,-1777,2237,-3253,-506,-4931,-7366,-8132,5406,-6300,-275,-1908,67,3569,1433,-7262,-437,8303,4498,-379,3054,-6285,4203,6908,4433,3077,2288,9733,-8067,3007,9725,9669,1362,-2561,-4225,5442,-9006,-429,160,-9234,-4444,3586,-5711,-9506,-79,-4418,-4348,-5891]
    # k = 93

    nums = [0,4,0,3,2]
    k=1

    # nums = [4,2,1,3,3]
    # k = 2
    sol = Solution()
    print(sol.findMaxAverage(nums, k))