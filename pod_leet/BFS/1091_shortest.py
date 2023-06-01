import collections
# the question specifies that the matrix is 8 directional, i.e we can travel diagonally as well
# in a regular BFS with a 2D matrix it's usually 4 directional i.e up, down, left, right
class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # use bfs
        queue = collections.deque([(0, 0, 1)]) # (x, y, path_len)
        if (grid[0][0] == 1 or grid[-1][-1] == 1):
            return -1
        if (grid[0][0]==0 and len(grid[0])==1 and len(grid)) == 1:
            return 1
        
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1), (1, -1), (-1, 1), (1, 1), (-1, -1)]
        
        while queue:
            x, y, path_len = queue.popleft()
            if x == len(grid)-1 and y == len(grid[0])-1:
                return path_len
            for dx, dy in directions:
                new_x, new_y = x + dx, y + dy
                if 0 <= new_x < len(grid) and 0 <= new_y < len(grid[0]) and grid[new_x][new_y] == 0: #make sure new_x and new_y are within the grid and the value is 0
                    grid[new_x][new_y] = 1 # mark as visited
                    queue.append((new_x, new_y, path_len+1))
        return -1
    
if __name__ == "__main__":
    s = Solution()
    # grid = [[0,1],[1,0]]
    # grid = [[1,0,0],[1,1,0],[1,1,0]]
    grid = [[0,0,0],[1,1,0],[1,1,0]]
    print(s.shortestPathBinaryMatrix(grid))