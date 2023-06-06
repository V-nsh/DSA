class Solution(object):
    def checkStraightLine(self, coordinates):
        """
        :type coordinates: List[List[int]]
        :rtype: bool
        """
        x1, y1 = coordinates[0]
        x2, y2 = coordinates[1]
        for i in range(2, len(coordinates)):
            x, y = coordinates[i]
            if (y2-y1)*(x-x1) != (y-y1)*(x2-x1):
                return False
        return True
    
if __name__ == "__main__":
    coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    print(Solution().checkStraightLine(coordinates)) # True