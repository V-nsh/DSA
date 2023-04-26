from level_order_102_max_depth_104 import Solution

class Symmetric(object):
    def isSymmetric(self, root):
        if root is None:
            return True
        return self.isMirror(root.left, root.right)
    
    def isMirror(self, left, right):
        if left is None or right is None:
            return left==right
        if left.val != right.val:
            return False
        
        return self.isMirror(left.left, right.right) and self.isMirror(left.right, right.left)
    
if __name__ == "__main__":
    s = Solution()
    sym = Symmetric()
    node =  int(input("Enter the number of nodes: "))
    for i in range(node):
        val = int(input("Enter next value: "))
        s.insert(val)
    print(sym.isSymmetric(s.root))