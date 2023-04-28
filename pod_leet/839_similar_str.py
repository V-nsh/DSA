from collections import defaultdict

class Solution(object):
    # two strings are similar if they are identical after swapping any two characters and maximum of 2 swaps
    # find the number of similar groups
    # eg: ["tars","rats","arts","star"]
    # here tars, rats, arts are similar but not star
    # so the answer is 2
    # so if S1 is similar to S2 and S2 is similar to S3 then this gives us a group [S1, S2, S3]
    # so we can think of this as a graph problem where each string is a node and if two nodes are similar then there is an edge between them
    # we can use a hashmap, for each hash[i] we store a list of indices of similar strings instead of string itself
    # we can use a set to keep track of visited nodes
    # we can use dfs to traverse the graph
    def numSimilarGroups(self, strs):
        n = len(strs)
        if n <= 1:
            return n
        # build the graph
        graph = defaultdict(list) #initialize with empty list
        for i in range(n):
            for j in range(i+1, n):
                if self.isSimilar(strs[i], strs[j]):
                    graph[i].append(j)
                    graph[j].append(i)
        # dfs
        visited = set()
        count = 0
        for i in range(n):
            if i not in visited:
                self.dfs(i, graph, visited)
                count += 1

        return count

    def dfs(self, node, graph, visited):
        visited.add(node)
        for i in graph[node]:
            if i not in visited:
                self.dfs(i, graph, visited)

    def isSimilar(self, s1, s2):
        count = 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                count += 1
                if count > 2:
                    return False
        return True
    
if __name__ == "__main__":
    s = Solution()
    # strs = ["tars","rats","arts","star"]
    strs = ["kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs"]
    print(s.numSimilarGroups(strs))