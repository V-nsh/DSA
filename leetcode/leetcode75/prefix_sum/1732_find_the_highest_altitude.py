import sys

class Solution(object):
    '''
    The idea is pretty simple, all you got to do is keep a track of the maximum sum so far.
    the altitude starts with 0, if -5 means the cyclist went downhill, if positive uphill AFTER the previous index
    '''
    def largestAltitude(self, gain):
        """
        :type gain: List[int]
        :rtype: int
        """
        maxAltSoFar, total = -sys.maxsize, 0
        for i in gain:
            total += i
            maxAltSoFar = max(maxAltSoFar, total)
        if maxAltSoFar<0:
            return 0
        return maxAltSoFar
    
if __name__=="__main__":
    # gain = [-5,1,5,0,-7]
    gain = [-4,-3,-2,-1,4,3,2]
    sol = Solution()
    print(sol.largestAltitude(gain))