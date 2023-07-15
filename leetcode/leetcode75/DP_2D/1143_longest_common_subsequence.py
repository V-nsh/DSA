class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        '''
        let there be Z be an LCS of A and B
        if am==bn then we append and element zk = am = bn

        if am != bn and zk != am then Z is theLCS of Am-1 and B
        same goes for if zk != bn then Z is the LCS of A and Bn-1
        '''

        '''
        from the above observation we can create a recursive solution:

        say we have a 2D array c of m*n size, and c[i][j] holds the length of LCS between Ai and Bj
        thus c[i][j]  = 0 if i or j is 0

        if there's a match, that is Ai==Bj
        then c[i][j] = c[i-1][j-1] + 1

        if the current elements are not equal then the LCS is greatest lenght out of all the previous subsequences
        i.e either LCS of Ai-1 and Bj or LCS of Ai and Bj-1 whichever of these is maximum.
        '''
        m = len(text1)
        n = len(text2)
        b = [["" for _ in range(n+1)] for _ in range(m+1)]
        c = [[0 for _ in range(n+1)] for _ in range(m+1)]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if text1[i-1]==text2[j-1]:
                    c[i][j] = c[i-1][j-1] + 1
                    b[i][j] = "\\"
                elif (c[i-1][j] >= c[i][j-1]):
                    c[i][j] = c[i-1][j]
                    b[i][j] = "|"
                else:
                    c[i][j] = c[i][j-1]
                    b[i][j] = "--"
        self.printLCS(b, text1, m-1, n-1)
        return c[m][n]
    
    def printLCS(self, b, X, i, j):
        if i==0 or j==0:
            return
        if b[i][j] == "\\":
            self.printLCS(b, X, i-1, j-1)
            print(X[i])
        elif b[i][j]=="|":
            self.printLCS(b, X, i-1, j)
        else:
            self.printLCS(b, X, i, j-1)
    
if __name__=='__main__':
    text1 = "oxcpqrsvwf"
    text2 = "shmtulqrypy"
    sol = Solution()
    print(sol.longestCommonSubsequence(text1, text2)) 