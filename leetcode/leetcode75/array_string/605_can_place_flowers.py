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
    
if __name__ == '__main__':
    flowerbed = [1,0,0,0,1,0,0]
    n = 2
    print(Solution().canPlaceFlowers(flowerbed, n))