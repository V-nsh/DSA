class Solution(object):
    def maxValue(self, n, index, maxSum):
        """
        :type n: int
        :type index: int
        :type maxSum: int
        :rtype: int
        """
        # we want to maximize the value at arr[index] however it is not feasible to check each value
        # so say we have maxSum 10 then we would need to check every value from 10->0
        # also not all elements can be 0 since abs(nums[i]-nums[i+1]) <= 1
        '''
        example Input: n = 6, index = 1,  maxSum = 10
        we want to maximize at index 1, so we start with max as 10
        0   1   2   3   4   5

        9   10  9   8   7   6   since the absolute difference should be <=1, not the correct ans
        8   9   8   7   6   5   reduce max by 1
        .
        .                       so on..
        2   3   2   1   1   1   not 0 because we are told for any nums[i] should be positive integers

        '''
        '''
        thus 3 is the solution, didn't type other solutions, just trust me bro.
        sum of elements: since the sequence would increase/decrease by 1 because of the condition in the problem, it behaves as an AP with common difference say 1.
        formula for AP Sn = (2a+(n-1)d)*n/2
        here a = A[1] and let's take d = 1
        since d=1, A[n] = A[1]+(n-1)
        therefore (n-1) = A[n] - A[1]
        therefore Sn = (2A[1] + A[n]-A[1])*n/2 since d=1
        therefore sum = (A[1]+A[n])*n/2

        So, at the end we want to calculate the sum of entire array while maximizing A[index] starting from maxSum to 1.
        It is obviously not feasible to find an array with each value till 1 and then find the sum and go on to next one, too slow.
        thus we go for a binary search on the possible values of A[index]
        say we want to go from 1-10
        starting from 10 if the sum is too high we move to left half or right half accordingly.

        so now for checking the left and right, there are two possibilities, either there is a series of 1s on the left or right or now.
        how do we find that there is a sequence of 1s or it is just and AP like[1,2,3,..val] or [1,1,..., val-index, val-.., val-1, val] 
        Note: we are looking at the left side array example, so the right most value is at index.

        so for left side:
        if value>index there are no 1s
        the sum is simply S= ((value-index) + value)*(index+1)//2
        else there are 1s
        then sum = (1+value)*value//2 + index-value+1
        we do +1 even on mid to avoid infinite loop. https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/editorial/comments/1924315

        for right side:
        we are basically looking from index = n-index to n-1, that is [value, value-(n-1)+index]
        thus if we have value>n-index (because the value is alread larger than the index we want to maximize, it cannot possibly have more 1s to it's right, same goes for the left)
        here the sum = (value+(value-(n-1))+index)*(n-index)//2 Note: we are adding index because at value-(n-1) we can't reach the requried sum, we will need to add index to leverage the number of possible 1s
        else there are 1s
        then sum = (value+1)*value//2+(n-index-value)
        '''

        def getSum(index, value, n):
            sum = 0
            if value>index:
                sum += (value+value-index)*(index+1)//2
            else:
                sum += (1+value)*value//2+ index-value+1
            
            # now right side
            if value>=n-index:
                sum += (value+value-n+1+index)*(n-index)//2
            else:
                sum += (value+1)*value//2 + (n-index-value)

            # since we are adding value twice, we need to subtract once from the total sum
            return sum-value

        def maxValue(n, index, maxSum):
            left, right = 1, maxSum
            while left<right:
                mid =  (left+right+1)//2
                if getSum(index, mid, n) <= maxSum:
                    left=mid
                else:
                    right = mid-1
            return left
        
