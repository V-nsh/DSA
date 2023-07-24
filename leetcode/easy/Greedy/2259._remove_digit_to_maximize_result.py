class Solution(object):
    # brute force
    def removeDigitBrute(self, number, digit):
        """
        :type number: str
        :type digit: str
        :rtype: str
        """
        ls = []
        for i in range(len(number)):
            if number[i]==digit:
                newstr = number[:i]+number[i+1:]
                ls.append(newstr)
        ls.sort()
        return ls[-1]
    
    # greedy/optimized
    def removeDigit(self, number, digit):
        digit_int = int(digit)
        currMax = -1
        for i in range(len(number)):
            if int(number[i]) == digit_int:
                num_without_digit = int(number[:i] + number[i + 1:])
                currMax = max(currMax, num_without_digit)
        return str(currMax)

if __name__=="__main__":
    number = "1231"
    digit = "1"
    sol = Solution()
    print(sol.removeDigit(number, digit))