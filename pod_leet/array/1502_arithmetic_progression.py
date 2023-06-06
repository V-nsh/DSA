class Solution(object):
    def canMakeArithmeticProgression(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        arr.sort()
        for i in range(1, len(arr)):
            if arr[i] - arr[i-1] != arr[1] - arr[0]:
                return False
        return True