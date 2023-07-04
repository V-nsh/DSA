from collections import defaultdict
import sys

class Solution(object):
    def minCostClimbingStairsBrute(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        # we reach top when we are out of list, this is not mentioned in the porblem description, kinda dumb
        # we can start at index 1 or 0, so we need to check for both
        graph = defaultdict(list)
        for i in range(len(cost)):
            graph[i].append(i+1)
            graph[i].append(i+2)
        print(graph)
        # we need to find the minimum cost to reach the top
        return min(self.dfs(0, graph, len(cost)-1, cost), self.dfs(1, graph, len(cost)-1, cost))
    
    def dfs(self, node , tree, target, cost):
        # because line 27 will run both possibilities for next jump, and next jump can be the target or one step before target, since we can jump two stairs, we even consider t-1
        if node==target or node==target-1:
            return cost[node]
        for i in tree[node]:
            return cost[node]+min(self.dfs(i, tree, target, cost), self.dfs(i+1, tree, target, cost))
        
    # top down approach aka memoization
    '''
    The idea is that we can either start from 1 or 0th index
    thus reaching nth index can be minimum of either the min cost required to reach the last index + cost of leaving that stair
        or min cost required the reach the previous of previous index + cost of leaving that one
    '''
    def minCostClimbingStairs(self, cost):
        sol = [0]*(len(cost)+1)
        sol[0] = 0
        sol[1] = 0
        for i in range(2, len(cost)+1):
            sol[i] = min(cost[i-1]+sol[i-1], sol[i-2]+cost[i-2])
        print(sol)
        return sol[-1]
    
    # bottom up aka tabulation approach
    '''
    we start with thinking what's the best cost to reach the last index, and the cost to stay on nth index can be started with 0, because it won't cost us to be there
    now to reach n from n-1 we only have one option 1 step thus that remains constant like in top down for first and second step, here last and second last are constant
    now for the generalizing part, the DP[i]th element can be decided as the least cost to reach i from the one previous to it or the one even before that
    this makes sense because going back up we will keep adding up previous one and eliminate the max of right now.
    '''
    def minCostClimbingStairsTabul(self, cost):
        cost.append(0)
        for i in reversed(range(len(cost)-3)):
            cost[i] += min(cost[i+2], cost[i+1])
        print(cost)
        return min(cost[:2])


if __name__ == '__main__':
    cost = [10, 15, 20]
    # cost = [1,100,1,1,1,100,1,1,100,1]
    s = Solution()
    # print(s.minCostClimbingStairsBrute(cost))
    # print(s.minCostClimbingStairs(cost))
    print(s.minCostClimbingStairsTabul(cost))