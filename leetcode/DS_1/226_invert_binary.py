from level_order_102_max_depth_104 import Solution
from collections import deque

class Invert(object):
    # apparently this is a not scalable
    def invertTree(self, root):
        if root is None:
            return None
        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root
    
    # this is basically level order or BFS
    def invertWithQeue(self, root):
        if root is None:
            return None
        queue = deque()
        queue.append(root)
        while queue:
            node = queue.popleft()
            node.left, node.right = node.right, node.left
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
        return root

if __name__ == "__main__":
    nodes =  int(input('Enter the number of nodes: '))
    s = Solution()
    for i in range(nodes):
        val = int(input('Enter next value: '))
        s.insert(val)
    inv = Invert()
    s.printTree2()
    inv.invertTree(s.root)
    print("new:")
    s.printTree2()