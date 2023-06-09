class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        for i in range(len(flowerbed)):
            if flowerbed[i]==1:
                continue
            if((i==0 or flowerbed[i-1]==0) and (i==len(flowerbed)-1 or flowerbed[i+1] == 0)):
                flowerbed[i] = 1
                n -= 1
        return n<=0
    
    def vivekApproach(self, flowerbed, n):
        for i in range(len(flowerbed)):
            if flowerbed[i]==1:
                continue
            elif flowerbed[i]==0 and flowerbed[i+1]==0 and flowerbed[i+2]==0:
                flowerbed[i+1]=1
                n -= 1
        print(flowerbed)
        return n<=0
    
if __name__ == '__main__':
    # flowerbed = [1,0,0,0,1,0,0]
    '''
     1 0 0 0 1
     ^
     i = 0
    flower[i] == 1: continue \/

    1 0 0 0 1
    ^ ^
    i = 1
    flower[i-1] == 0 and flower[i+1] == 0
    yaha flower plant nahi kar sakte hai

    1 0 0 0 1
    ^ ^ ^
    i = 2
    flower[i-1]  and flower[i+1] ==0
    yaha to karenge
    flower[i] = 1

    1 0 1 0 1
    '''


    '''
    0 0 0 0 0 >
            ^   
    i = 4

    '''
    flowerbed = [0, 0, 0, 0, 1]
    # flowerbed = [1, 0, 0]
    n = 1
    print(Solution().canPlaceFlowers(flowerbed, n))