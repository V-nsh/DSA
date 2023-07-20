class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        j, i = 0, 0
        while i<len(t) and j<len(s):
            if s[j]==t[i]:
                j+=1
        return j==len(s)
    
if __name__=="__main__":
    sol = Solution()
    # s = "axc"
    # t = "ahbgdc"
    s = ""
    t = "ahbgdc"
    print(sol.isSubsequence(s, t))