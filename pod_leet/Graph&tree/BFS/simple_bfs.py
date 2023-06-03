import collections

class Graph(object):
    def __init__(self):
        self.directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        self.visited = list()

    def BFS(self, graph):
        queue = collections.deque([(0, 0)]) # (x, y)
        visited = [[False for _ in range(len(graph[0]))] for _ in range(len(graph))]
        visited[0][0] = True
        while queue:
            x, y  = queue.popleft()
            print(graph[x][y], end=" ")

            for dx, dy in self.directions:
                x_new, y_new = x + dx, y + dy
                if(0 <= x_new < len(graph) and 0 <= y_new < len(graph[0]) and not visited[x_new][y_new] and graph[x_new][y_new]):
                    queue.append((x_new, y_new))
                    visited[x_new][y_new] = True

if __name__ == "__main__":
    # graph = [[1, 1, 0, 0, 0], 
    #          [0, 1, 0, 0, 1], 
    #          [1, 0, 0, 1, 1], 
    #          [0, 0, 0, 0, 0], 
    #          [1, 0, 1, 0, 1]]
    graph= [[ 1, 2, 3, 4 ],
           [ 5, 6, 7, 8 ],
           [ 9, 10, 11, 12 ],
           [ 13, 14, 15, 16 ]]
    g = Graph()
    g.BFS(graph)