class Solution(object):
    def minFlips(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        # I did not do this myself.
        ab, equal, ans = a | b, (a | b) ^ c, 0
        for i in range(31):
            mask = 1 << i
            if equal & mask > 0:
                ans += 2 if (a & mask) == (b & mask) and (c & mask) == 0 else 1
        return ans