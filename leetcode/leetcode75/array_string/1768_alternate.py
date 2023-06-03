class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        result = []
        for i in range(min(len(word1), len(word2))):
            result.append(word1[i])
            result.append(word2[i])
        if len(word1) > len(word2):
            result.append(word1[len(word2):])
        elif len(word1) < len(word2):
            result.append(word2[len(word1):])
        return ''.join(result)
    
if __name__ == '__main__':
    word1 = "abc" 
    word2 = "pqr"
    s = Solution()
    print(s.mergeAlternately(word1, word2))