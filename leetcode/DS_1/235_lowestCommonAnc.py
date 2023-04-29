from level_order_102_max_depth_104 import Solution

class LCA(object):
    def lowestCommonAncestor(self, root, p, q):
        cur = root
        while cur:
            if cur.val > p.val and cur.val > q.val:
                cur = cur.left
            elif cur.val < p.val and cur.val < q.val:
                cur = cur.right
            else:
                return cur