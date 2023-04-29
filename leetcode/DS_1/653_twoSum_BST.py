from level_order_102_max_depth_104 import Solution
from collections import deque

class TwoSumBST(object):
    def inorder(self, root, queue):
        if root is None:
            return
        self.inorder(root.left, queue)
        queue.append(root.val)
        self.inorder(root.right, queue)

    def findTarget(self, root, k):
        queue = deque()
        self.inorder(root, queue)
        while queue:
            val = queue.popleft()
            if k-val in queue:
                return True
        return False
    
if __name__ == "__main__":
    nodes = int(input('Enter the number of nodes: '))
    s = Solution()
    for i in range(nodes):
        val = int(input('Enter next value: '))
        s.insert(val)
    twoSum = TwoSumBST()
    print(twoSum.findTarget(s.root, 9))