from level_order_102_max_depth_104 import Solution

class IsValid(object):
    def isValidHelper(self, root, minVal, maxVal):
        if root is None:
            return True
        if root.val <= minVal or root.val >= maxVal:
            return False
        return self.isValidHelper(root.left, minVal, root.val) and self.isValidHelper(root.right, root.val, maxVal)
    
    def isValidBST(self, root):
        if root is None:
            return True
        return self.isValidHelper(root, float('-inf'), float('inf'))
    

if __name__ == "__main__":
    s = Solution()
    valid = IsValid()
    node = int(input("Enter the number of nodes: "))
    for i in range(node):
        val = int(input("Enter next value: "))
        s.insert(val)
    print(valid.isValidBST(s.root))