class Solution(object):
    vowels = set("AEIOUaeiou")
    def isVowel(self, s):
        return 1 if s in self.vowels else 0

    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if len(s)==1:
            return self.isVowel(s[0])
        elif len(s)==0:
            return 0
        total = 0
        for i in range(k):
            if self.isVowel(s[i]):
                total += 1
        maxSofar = total
        for j in range(k, len(s)):
            if self.isVowel(s[j-k]):
                total -= 1
            if self.isVowel(s[j]):
                total += 1
            maxSofar = max(maxSofar, total)
        return maxSofar
    
if __name__ == "__main__":
    s = "abciiidef"
    k = 3
    # s = "leetcode"
    # k = 3
    sol = Solution()
    print(sol.maxVowels(s, k))