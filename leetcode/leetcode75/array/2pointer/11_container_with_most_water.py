class Solution(object):
    # brute force
    def maxAreaBrute(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        area = 0
        for i in range(len(height)):
            for j in range(i+1, len(height)):
                area = max(area, min(height[i], height[j])*(j-i))
        return area
    
    '''
    * The widest container (using first and last line) is a good candidate, because of its width. Its water level is the height of the smaller one of first and last line.
    * All other containers are less wide and thus would need a higher water level in order to hold more water.
    * The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.
    '''
    def maxArea(self, height):
        i, j = 0, len(height)-1
        area = 0
        while i<j:
            area = max(area, min(height[i], height[j])*(j-i))
            if height[i]<height[j]:
                i += 1
            else:
                j -= 1
        return area

if __name__ == "__main__":
    height = [1,8,6,2,5,4,8,3,7]
    sol = Solution()
    print(sol.maxArea(height))