from level_order_102_max_depth_104 import Solution

class pathSum(object):
    # we need this because leetcode function didn't have the currSum parameter
    # the recursion simply opens up every branch and checks if the sum is equal to target
    def dfsHelper(self, node, currSum, targetSum):
        if node is None:
            return False
        currSum += node.val
        if node.left is None and node.right is None:
            return currSum == targetSum
        
        return (self.dfsHelper(node.left, currSum, targetSum) or self.dfsHelper(node.right, currSum, targetSum))

    def hasPathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: bool
        """
        return self.dfsHelper(root, 0, targetSum)
    
if __name__ == "__main__":
    nodes = int(input("Enter the number of nodes: "))
    s = Solution()
    for i in range(nodes):
        val = int(input('Enter next value: '))
        s.insert(val)
    path = pathSum()
    print(path.hasPathSum(s.root, 22))