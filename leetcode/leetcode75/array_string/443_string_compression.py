class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        # two pointers can be used, one which tracks the same chars and one that halts when we reach a different char.
        i, j, n = 0, 0, len(chars)
        while i < n:
            i=j
            while j<n and chars[i]==chars[j]:
                j+=1
            if j-i>1:
                chars[i+1:j]=str(j-i) #this is atrocius, we are converting the number to string and then adding it to the list
                n=len(chars)
                # we need to go back to where the last char was and start from there
                # that is we need to go back to where the updated list that we visited so far ends.
                j=i+1+len(str(j-i))
            # adding 1 to i because we need to move to the next char
            i+=1
        return chars
    
if __name__=="__main__":
    s = Solution()
    # chars = ["a","a","b","b","c","c","c"]
    # chars = ["a"]
    # chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
    chars = ["p","p","p","p","m","m","b","b","b","b","b","u","u","r","r","u","n","n","n","n","n","n","n","n","n","n","n","u","u","u","u","a","a","u","u","r","r","r","s","s","a","a","y","y","y","g","g","g","g","g"]
    print(s.compress(chars))