class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s[::-1]
        i, j =0, 0
        n = len(s)
        s = list(s)
        while i< n:
            # here we need to reverse all the words now since our string is totally reversed.
            # we use two pointers, i and j. i marks the start of the word and j marks the end
            while(i<j or (i<n and s[i]==' ')):
                i+=1
            while(j<i or (j<n and s[j]!=' ')):
                j+=1
            s[i:j] = s[i:j][::-1]
        s = ''.join(s)
        # to remove extra spaces in other languages, this is a great approach 
        # https://leetcode.com/problems/reverse-words-in-a-string/solutions/47720/clean-java-two-pointers-solution-no-trim-no-split-no-stringbuilder/?envType=study-plan-v2&envId=leetcode-75
        return ' '.join(s.split())
    
if __name__=='__main__':
    s = Solution()
    print(s.reverseWords("the sky is blue"))
    print(s.reverseWords("a good  example"))