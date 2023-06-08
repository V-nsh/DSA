class Solution(object):
    def countNegatives(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # some weird approach I found in the discussion
        # ++++++
        # ++++--
        # ++++--
        # +++---
        # +-----
        # +-----
        # if you see above the negative form a staircase, so the idea is to find the length of the staircase
        m = len(grid)
        n = len(grid[0])
        row = m-1
        c, count = 0, 0
        # so start from bottom row and first column
        while row >= 0  and c <  n :
            if grid[row][c] < 0:
                count += n-c
                row -= 1
            else:
                c+=1
        return count
    
if __name__ == "__main__":
    obj = Solution()
    grid = [[4,3,2,-1],
            [3,2,1,-1],
            [1,1,-1,-2],
            [-1,-1,-2,-3]]
    out = obj.countNegatives(grid)
    print(out)
    grid = [[3,2],[1,0]]
    out = obj.countNegatives(grid)
    print(out)
    grid = [[1,-1],[-1,-1]]
    out = obj.countNegatives(grid)
    print(out)
    grid = [[-1]]
    out = obj.countNegatives(grid)
    print(out)