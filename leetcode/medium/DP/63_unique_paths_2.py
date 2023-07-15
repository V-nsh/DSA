class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        '''
        similar to unique paths 1, but we need to check if the cell is an obstacle or not
        '''
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        DP = [[0 for _ in range(n)] for _ in range(m)]
        # missed the case where first or last cell is an obstacle
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                break
            DP[i][0] = 1
        for j in range(n):
            if obstacleGrid[0][j] == 1:
                break
            DP[0][j] = 1

        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] != 1:
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1]
        return DP[m - 1][n - 1]
    
if __name__ == "__main__":
    # obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    obstacleGrid = [[0,0],[0,1]]
    print(Solution().uniquePathsWithObstacles(obstacleGrid))