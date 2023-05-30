class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        # we can use the approach of coloring the nodes
        # every adjacent node should be of different color, in this way a cycle with only even number of nodes can be bipartite.
        # color = {}
        # queue = []
        # queue.append(0)
        # color[0] = 1
        # while queue:
        #     node = queue.pop(0)
        #     for i in range(len(graph[node])):
        #         if graph[node][i] not in color:
        #             color[graph[node][i]] = 1 - color[node]
        #             queue.append(graph[node][i])
        #         elif color[graph[node][i]] == color[node]:
        #             print('from false')
        #             return color
                
        # return color

        color = {}
        queue = []
        for i in range(len(graph)):
            color[i] = -1
        queue.append(0)
        color[0] = 1
        while queue:
            node = queue.pop(0)
            if graph[node] == []:
                if node+1 < len(graph):
                    for j in graph[node+1]:
                        queue.append(j)
                continue
            for neighbors in graph[node]:
                if color[neighbors] == -1:
                    color[neighbors] = 1 - color[node]
                    queue.append(neighbors)
                elif neighbors != node and color[neighbors] == color[node]:
                    return False
                
        print(color)
        return True

if __name__ == "__main__":
    # graph = [[1,3],[0,2],[1,3],[0,2]]
    graph  = [[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]
    s = Solution()
    print(s.isBipartite(graph))