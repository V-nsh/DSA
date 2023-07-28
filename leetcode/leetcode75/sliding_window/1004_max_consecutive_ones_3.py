class Solution(object):
    def longestOnesNope(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        '''
        you cannot have >k 0s in a window, that's the max you can have
        '''

        '''
        the following code is mostly incorrect, what I thought at first was I would find a way to remove the extra 0 just move to the end and start anew
        but that doesn't really make sense
        '''
        if len(nums)==1:
            return 1
        elif len(nums)==2:
            return 2
        fromHere, toHere = 0, 0
        total, maxSoFar, numZeros = 0, 0, 0
        for i in range(len(nums)):
            if numZeros <= k:
                if nums[i]==0:
                    numZeros += 1
                total += 1
                toHere = i
            else:
                break
        startFresh = toHere
        maxSoFar = total
        for j in range(startFresh, len(nums)):
            if nums[j]==0:
                if numZeros<=k:
                    total += 1
                    numZeros += 1
                else:
                    maxSoFar = max(maxSoFar, total)
                    total = 0
            else:
                total += 1

        '''
        instead of *moving* the window, think about expanding and shrinking it since we are not given any particular length as well
        but we have max number of zeros, so we move right as long as we have zeros_soFar < k
        if it exceeds when adding the current element we start shrinking the window from left
        in between we will keep a track of the maximum length so far and the length of last window.
        '''
    def longestOnes(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        left, zeroSoFar, maxLength = 0, 0, 0
        for right in range(len(nums)):
            if nums[right]==0:
                zeroSoFar += 1
            while zeroSoFar>k:
                if nums[left]==0:
                    zeroSoFar-=1
                left+=1
            maxLength = max(maxLength, right-left+1)
        return maxLength
    
    def LongestOnesTotalVar(self, nums, k):
        left, zeroSoFar, maxLength, total = 0, 0, 0, 0
        for right in range(len(nums)):
            if nums[right]==0:
                zeroSoFar += 1
            while zeroSoFar>k:
                if nums[left]==0:
                    zeroSoFar-=1
                left+=1
                total-=1
            total += 1
            maxLength = max(maxLength, total)
        return maxLength

if __name__=="__main__":
    nums = [1,1,1,0,0,0,1,1,1,1,0]
    k = 2
    sol = Solution()
    print(sol.LongestOnesTotalVar(nums, k))