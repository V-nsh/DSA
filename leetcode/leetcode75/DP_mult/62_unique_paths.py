class Solution(object):
    def uniquePathsTopDown(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        DP = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            DP[i][0] = 1
        for j in range(n):
            DP[0][j] = 1
        for i in range(1, m):
            for j in range(1, n):
                DP[i][j] = DP[i - 1][j] + DP[i][j - 1]
        return DP[m - 1][n - 1]
    

    # All we are doing is adding up the number of ways to reach the corner most cell from the right + bottom cell of current cell
    # reaching the corner one from itslef has 1 way, and there's only 1 way of reaching from the cell just above and left of it
    # that's why we fill up those cells with 1
    def uniquePathsBottomUp(self, m , n):
        DP = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            DP[i][n-1] = 1
        for j in range(n):
            DP[m-1][j] = 1
        for i in reversed(range(m-1)):
            for j in reversed(range(n-1)):
                DP[i][j] = DP[i][j+1] + DP[i+1][j]
        return DP[0][0]
    
if __name__ == "__main__":
    m = 3
    n = 2
    print(Solution().uniquePathsBottomUp(m, n))