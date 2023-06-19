# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# this can be done using inorder traversal
class Solution(object):
    min = float('inf')
    previous = None
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return 0
        self.getMinimumDifference(root.left)

        if self.previous:
            self.min = min(self.min, root.val - self.previous.val)
        self.previous = root
        self.getMinimumDifference(root.right)
        return self.min

if __name__ == '__main__':
    root = TreeNode(4)
    root.right = TreeNode(6)
    root.left = TreeNode(2)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)
    print(Solution().getMinimumDifference(root))