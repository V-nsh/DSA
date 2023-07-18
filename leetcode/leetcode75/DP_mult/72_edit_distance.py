class Solution(object):
    # brute force
    def minDistanceBrute(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        if len(word1)==0:
            return len(word2)
        if len(word2)==0:
            return len(word1)
        if word1[0]==word2[0]:
            return self.minDistanceBrute(word1[1:], word2[1:])
        else:
            return min(self.minDistanceBrute(word1[1:], word2), self.minDistanceBrute(word1, word2[1:]), self.minDistanceBrute(word1[1:], word2[1:])) + 1
            #                                 ^ delete word1[0]                           ^ insert at word1                         ^ replace word1[0] with word2[0]
    # DP
    def minDistance(self, word1, word2):
        '''
        this is just modified version of longest common subsequence
        we can thing of it as going to the next block must be the best of either replacing, deleting or inserting an element in w1
        to correlate this to LCS let's say we have a common subsequence Z between w1 and w2
        note: here we write w2 on top of matrix and w1 on the left side of matrix
        if w1[i]=w2[i]=z then we move ahead, if not:
            we take the minimum of these three operations:
                insert: dp[i][j-1]+1
                delete: dp[i-1][j]+1
                replace: dp[i-1][j-1]+1
        recall we 0s in the first row and column of the matrix for LCS and started with 1,1 index
        because 0th row and 0th index are empty to change from an empty string to string of length i we append i at dp[i][0]
        example matrix between "abc" and "adc"
        0 1 2 3
        1 0 2 3
        2 2 1 2
        3 3 2 1
        '''
        m = len(word1)
        n = len(word2)
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        # the reason behind this is that, if we start from an empty string at [i, 0] then to change it to word2, that is the word we have kept on top, we will need to insert i elements
        # thus dp[i][0] = i
        for i in range(m+1):
            dp[i][0] = i
        for j in range(n+1):
            dp[0][j] = j
        for i in range(1, m+1):
            for j in range(1, n+1):
                if word1[i-1]==word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1

        return dp[m][n]
if __name__=='__main__':
    word1 = "horse"
    word2 = "ros"
    s = Solution()
    print(s.minDistanceBrute(word1, word2))
    print(s.minDistance(word1, word2))