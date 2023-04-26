from collections import deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def __init__(self):
        self.root = None 
        self.queue = deque()

    def maxDepth(self, root):
        if root is None:
            return 0
        lheight = self.maxDepth(root.left)
        rheight = self.maxDepth(root.right)
        if(lheight > rheight):
            return lheight+1
        else:
            return rheight+1
        
    # To solve this we can use BFS, thus we will use a queue
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        # so the approach is, we will use a queue and append the root to it
        # then we will pop the first element and append it to the result
        # then we will append the left and right child of the popped element to the queue
        # we will do this until the queue is empty
        res = []
        if root is None:
            return res
        queue = deque()
        queue.append(root)

        while queue:
            level = []
            for i in range(len(queue)):
                node = queue.popleft()
                level.append(node.val)
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
            res.append(level)

        return res

    def insert(self, val):
        if self.root is None:
            self.root = TreeNode(val)
        else:
            self._insert(val, self.root)

# this is a BST as we are comparing the value of the node with the value of the root and inserting accordingly
    def _insert(self, val, root):
        if val < root.val:
            if root.left is None:
                root.left = TreeNode(val)
            else:
                self._insert(val, root.left)
        elif val > root.val:
            if root.right is None:
                root.right = TreeNode(val)
            else:
                self._insert(val, root.right)
                # the else part was actually useless for problem 701 but meh...
        else:
            pass
    
    # use this to insert in a simple binary tree
    def _insertSimple(self, value, root):
        if root.left is None:
            root.left = TreeNode(value)
        elif root.right is None:
            root.right = TreeNode(value)
        else:
            self._insertSimple(value, root.left)

# this is actually correct
    def _insertSimple2(self, value, root):
        self.queue.append(root)
        while self.queue:
            currentNode = self.queue.popleft()
            if currentNode.left is None:
                currentNode.left = TreeNode(value)
                break
            elif currentNode.right is None:
                currentNode.right = TreeNode(value)
                break
            else:
                self.queue.append(currentNode.left)
                self.queue.append(currentNode.right)
            

# this is stupid, don't use this
    def createTreeNode(self):
        val = int(input("Enter next value: "))
        if val == -1:
            return None
        root = TreeNode(val)
        root.left = self.createTreeNode()
        root.right = self.createTreeNode()
        return root
    
    def printTree(self, root):
        if root == None:
            return
        # print(root.val)
        self.printTree(root.left)
        print(root.val)
        self.printTree(root.right)

    def printTree2(self):
        self.printTree(self.root)   

if __name__ == "__main__":
    s = Solution()
    node =  int(input("Enter the number of nodes: "))
    for i in range(node):
        val = int(input("Enter next value: "))
        s.insert(val)
    # print(s.levelOrder(root))
    # s.printTree2()
    height = s.maxDepth(s.root)
    res = s.levelOrder(s.root)
    print("height of the tree is: ", height)
    print(res)