import sys

class Solution(object):
    def increasingTripletBruteForce(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # brute force
        n = len(nums)
        if n<3:
            return False
        for i in range(0,n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    if nums[i] < nums[j] and nums[j] < nums[k]:
                        return True
        return False
    
    def increasingTripletOnSpace(self, nums):
        # optimum approach with two arrays, one for storing the minimum element on the left of ith elemnt
        # another array to store the maximum value to the right of ith element.
        # this takes O(n) time and O(n) space since we are creating extra array
        n = len(nums)
        if n<3:
            return False
        leftMin = [0]*n
        rightMax = [0]*n
        leftMin[0] = nums[0]
        rightMax[n-1] = nums[n-1]
        for i in range(1, n):
            leftMin[i] = min(leftMin[i-1],nums[i])
        for j in reversed(range(0, n-1)):
            rightMax[j] = max(rightMax[j+1], nums[j])
        print(leftMin)
        print(rightMax)
        for i in range(0, n):
            if leftMin[i]<nums[i] and nums[i]<rightMax[i]:
                return True
        return False
    
    def increasingTriplet(self, nums):
        # a very subtle way of thinking is using just two variables, declaring them firstSmallest and then secondSmallest
        # naturally the third one will be larger than both, thus if the next num at num[i] is smaller than first we replace
        # or else it is greater than firstSmallest and might be smaller than secondSmaller, if it is replace with second.
        # if not it is greater than both and the first is already smaller than second and second is smaller than third.
        # this will take O(n) time and O(1) space
        firstSmallest, secondSmallest = sys.maxsize, sys.maxsize
        for i in nums:
            if i<=firstSmallest:
                firstSmallest=i
            elif i<=secondSmallest:
                secondSmallest=i
            else:
                return True
        return False
    
if __name__=="__main__":
    s = Solution()
    # nums = [1,2,3,4,5]
    # nums = [5,4,3,2,1]
    nums = [2,1,5,0,4,6]
    print(s.increasingTriplet(nums))