class Solution(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        '''
        a tribonacci works like a fibonacci but with 3 numbers
        it starts with 0, 1, 1
        and then the next number is the sum of the previous 3 numbers
        so the tribonacci sequence is 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, ...
        '''
        dp = [0, 1, 1]
        for i in range(3, n+1):
            dp[i%3] = sum(dp)
            # the loop will end at n, so i%3 is actually n%3 at the end, thus the solution will lie at n%3
        return dp[n%3]
    
    # recursive solution
    # TLE lmao
    def tribonacciRecurse(self, n):
        if n<2: return n
        if n==2: return 1
        return self.tribonacciRecurse(n-1)+self.tribonacciRecurse(n-2)+self.tribonacciRecurse(n-3)
    
    # straight forward approach
    def tribonacciStraight(self, n):
        if n<2: return n
        a, b, c = 0, 1, 1
        while n>2:
            d = a+b+c
            a = b
            b = c
            c = d
            n -= 1
        return c
if __name__=='__main__':
    # n = 4
    n = 30
    s = Solution()
    print(s.tribonacciRecurse(n))

# https://leetcode.com/problems/n-th-tribonacci-number/solutions/1482728/c-python-2-solutions-dp-matrix-exponential-picture-explained-clean-concise/