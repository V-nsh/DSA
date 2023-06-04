class Solution(object):
    def findCircleNum(self, isConnected):
        """
        :type isConnected: List[List[int]]
        :rtype: int
        """
        visited = [False for _ in range(len(isConnected))]
        count  = 0
        for index in range(len(isConnected)):
            if not visited[index]:
                self.dfs(isConnected, index, visited)
                count+=1
        return count
    
    def dfs(self, isConnected, index, visited):
        # for i in range(len(isConnected[index])):
        for i, conn in enumerate(isConnected[index]):
            if conn == 1 and not visited[i]:
            # if isConnected[index][i] == 1 and not visited[i]:
                visited[i] = True
                self.dfs(isConnected, i, visited)
            
if __name__ == "__main__":
    # isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    isConnected = [[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]
    print(Solution().findCircleNum(isConnected)) # 2