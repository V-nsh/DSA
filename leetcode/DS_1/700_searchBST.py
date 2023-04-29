from level_order_102_max_depth_104 import Solution

class SearchBST(object):
    def searchBST(self, root, val):
        if root is None:
            return None
        if root.val == val:
            return root
        if root.val < val:
            return self.searchBST(root.right, val)
        if root.val > val:
            return self.searchBST(root.left, val)
        
    def printBST(self, root):
        if root is None:
            return
        print(root.val)
        self.printBST(root.left)
        self.printBST(root.right)
        
if __name__ == "__main__":
    s = Solution()
    search = SearchBST()
    node = int(input("Enter the number of nodes: "))
    for i in range(node):
        val = int(input("Enter next value: "))
        s.insert(val)
    newRoot = search.searchBST(s.root, 2)
    search.printBST(newRoot)