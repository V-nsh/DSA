# dumb problem, all you have to do is take the square root of number of bulbs
# What the problem says is, you are given n bulbs, in first round all bulbs are toggled on, in second round multiples of 2 are toggled on/off and so on
# thus if we think about it only those with odd factors are toggled on at the end
# perfect squares have odd factors, thus we need to find the number of perfect squares less than n
class Solution(object):
    def bulbSwitch(self, n):
        # sqrt(n) gives the number of perfect squares less than n becuase sqrt(n) * sqrt(n) = n
        return int(n**0.5)
    
if __name__ == "__main__":
    n = int(input("Enter the number of bulbs: "))
    s = Solution()
    print(s.bulbSwitch(n))