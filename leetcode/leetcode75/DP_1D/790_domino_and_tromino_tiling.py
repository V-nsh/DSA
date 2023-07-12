class Solution(object):
    def numTilingsCopilot(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = []
        dp.append(1)
        dp.append(1)
        dp.append(2)
        for i in range(3, n+1):
            dp.append(2*dp[i-1]+dp[i-3])
        return dp[n]%1000000007
    
    # copilot is scary as hell, it just gave me this link and the code above.
    # https://leetcode.com/problems/domino-and-tromino-tiling/discuss/113531/Java-O(logn)-time-O(1)-space-solution-with-explanation

    def numTilings(self, n):
        MOD = 10**9+7

        # caching the results
        hasEvenBool = [False]*(n+1)
        evenCache = [None]*(n+1)

        '''
        Event is for adding a single veritcal or horizontal domino
        '''
        def even(n):
            if n==0:
                return 1
            
            if hasEvenBool[n]:
                return evenCache[n]
            count = 0
            # add a vertical domino
            count += even(n-1)
            # if it is possible to place a horizontal domino we try that possibility as well
            if n-2>=0:
                count += even(n-2)
                # or we can try with a tromino, for tromino we will have a single tile sticking out so we make another function to handle that.
                # for a tromino we will have 2 of them to complete each other
                count += 2* odd(n-2)
            hasEvenBool[n] = True
            evenCache[n] = count%MOD
            return count % MOD
        
        hasOddBool = [False]*(n+1)
        oddCache = [None]*(n+1)
        def odd(n):
            # so what this function does is that it adds a tromino to the remaining piece
            # so we have to make sure that the remaining piece is even
            if n==0:
                return 0
            
            if hasOddBool[n]:
                oddCache[n]
            count = 0
            # because we are adding a single tile to the remaining piece
            # here we can either add a horizontal or just a tromino.
            '''
            a horizontal domino can be added in between two trominos as well like this
            . |  -  - | .
            . |  .  . | .
            the dashes in the middle is a horizontal domino and two trominos are on the sides
            '''
            count += even(n-1)
            count += odd(n-1)

            hasOddBool[n] = True
            oddCache[n] = count % MOD
            return count % MOD
        
        return even(n) % MOD
        
if __name__=='__main__':
    n = 5
    s = Solution()
    print(s.numTilings(n))