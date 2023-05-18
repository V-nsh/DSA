class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        # all we need to is to find nodes with indegree 0
        # we can use a set to keep track of nodes with indegree 0
        ans = set()
        for i in range(n):
            ans.add(i)
        for i in range(len(edges)):
            # if a node is in the edge list at location 1 then it has an indegree > 0 because we are reaching there from edges[i][0]
            ans.discard(edges[i][1])
        return list(ans)
    
if __name__ == "__main__":
    edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
    n = 6
    s = Solution()
    print(s.findSmallestSetOfVertices(n, edges))