import sys

class Solution(object):
    def __init__(self, numNodes):
        self.visited = [-sys.maxsize]*numNodes

    def dfs(self, node, graph):
        self.visited[node] = node
        print(node)
        if node in graph:
            for i in graph[node]:
                if i not in self.visited:
                    self.dfs(i, graph)

if __name__=='__main__':
    graph = {
        0: [1, 3],
        1: [2],
        2: [5,6,7]
    }
    s = Solution(8)
    s.dfs(0, graph)