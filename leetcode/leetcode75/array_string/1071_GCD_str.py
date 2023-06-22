class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        # str1 and str2 have a gcd iff str1 + str2 == str2 + str1
        # another approach: if longer string starts with shorter keep cutting off common prefix from longer until empty
        # if longer does not start with shorter then no gcd
        if str1 + str2 != str2 + str1: 
            return ""
        if not str1 or not str2: 
            return str1 if str1 else str2
        
        if len(str1) < len(str2): 
            return self.gcdOfStrings(str2, str1)
        elif str1[:len(str2)] == str2: 
            return self.gcdOfStrings(str1[len(str2):], str2)
        else: 
            return ""

if __name__ == '__main__':
    str1 = "ABABAB"
    str2 = "ABAB"
    print(Solution().gcdOfStrings(str1, str2))