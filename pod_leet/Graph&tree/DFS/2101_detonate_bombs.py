# calculate distance between each bomb and create a graph/2D matrix for it, then use DFS to find which node can reach the most bombs
import collections
class Solution(object):

    def dfs(self, graph, start, visited, count):
        visited[start] = True
        count[0] += 1
        for i in graph[start]:
            if not visited[i]:
                self.dfs(graph, i, visited, count)

    def maximumDetonation(self, bombs):
        """
        :type bombs: List[List[int]]
        :rtype: int
        """
        graph = [[] for _ in range(len(bombs))]
        for i in range(len(bombs)):
            x, y, r = bombs[i]
            for j in range(len(bombs)):
                if i == j:
                    continue
                x2, y2, r2 = bombs[j]
                distance =  (x2-x)**2 + (y2-y)**2
                if distance <= r**2:
                    graph[i].append(j)
        ans = float('-inf')

        for i in range(len(bombs)):
            count = [0]
            visited = [False for _ in range(len(bombs))]
            self.dfs(graph, i, visited, count)
            ans= max(ans, count[0])

        return ans
    
    # using adj list
    def maximumDetonation2(self, bombs):
        adj = collections.defaultdict(list)
        for i in range(len(bombs)):
            for j in range(i+1, len(bombs)):
                x1, y1, r1 = bombs[i]
                x2, y2, r2 = bombs[j]
                distance = (x2-x1)**2 + (y2-y1)**2
                if distance <= r1**2:
                    adj[i].append(j)
                if distance <= r2**2:
                    adj[j].append(i)
        result = 0
        for i in range(len(bombs)):
            result =  max(result, self.dfs1(i, set(), adj))

        return result
        
    def dfs1(self, start, visited, adj):
        if start in visited:
            return 0
        visited.add(start)
        for neighbor in adj[start]:
            self.dfs1(neighbor, visited, adj)
        return len(visited)
    

if __name__ == "__main__":
    bombs = [[2,1,3],[6,1,4]]
    s = Solution()
    print(s.maximumDetonation2(bombs))
