class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = []
        for i in range(len(s)):
            if s[i] in "aeiouAEIOU":
                res.append(i)
        start, end = 0, len(res)-1
        while start<end:
            s[res[start]], s[res[end]] = s[res[end]], s[res[start]]
            start+=1
            end-=1
        return "".join(s)
    
if __name__ == '__main__':
    s = Solution()
    print(s.reverseVowels(["h","e","l","l","o"]))
    print(s.reverseVowels(["H","a","n","n","a","h"]))