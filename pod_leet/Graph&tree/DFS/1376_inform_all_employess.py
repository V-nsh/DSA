import collections

class Solution(object):
    # correct but MLE
    # one way to optimize is to use adj list instead of adj matrix and get rid of visited since tree structure is gauranteed
    def numOfMinutes(self, n, headID, manager, informTime):
        """
        :type n: int
        :type headID: int
        :type manager: List[int]
        :type informTime: List[int]
        :rtype: int
        """
        # build an adj matrix with informTime as weight
        n = len(manager)
        graph = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            if manager[i]!=-1:
                graph[manager[i]][i] = informTime[manager[i]]
        visited = [False for _ in range(n)]
        self.print_graph(graph)
        return self.dfs(graph, headID, visited, 0)

    def print_graph(self, graph):
        for i in range(len(graph)):
            print(graph[i])

        # dfs
    def dfs(self, graph, start, visited, time):
        maxi=0
        if visited[start]:
            return maxi
        visited[start] = True
        for i in range(len(graph[start])):
            if graph[start][i]!=0:
                maxi = max(maxi, self.dfs(graph, i, visited, graph[start][i]))
        return maxi+time
    
    def numOfMinutes2(self, n, headID, manager, informTime):
        n= len(manager)
        graph = [[] for _ in range(n)]
        for i in range(n):
            if manager[i]!=-1:
                graph[manager[i]].append(i)
        def dfs(i):
            return max([dfs(j) for j in graph[i]] or [0]) + informTime[i]
        return dfs(headID)
    
    # optimized approach for the first self approach
    def numOfMinutes3(self, n, headID, manager, informTime):
        graph = collections.defaultdict(list)
        for i in range(len(manager)):
            if manager[i]!=-1:
                graph[manager[i]].append(i)
        return self.optimizedDFS(graph, headID, informTime)

    def optimizedDFS(self, graph, node, informTime):
        if not graph[node]:
            return 0
        return max([self.optimizedDFS(graph, child, informTime) for child in graph[node]]) + informTime[node]
    
if __name__=="__main__":
    n = 7
    headID = 6
    manager = [1,2,3,4,5,6,-1]
    informTime = [0,6,5,4,3,2,1]
    print(Solution().numOfMinutes(n, headID, manager, informTime)) # 21