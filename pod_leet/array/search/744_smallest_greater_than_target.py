class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        if target >= letters[-1] or target < letters[0]:
            return letters[0]
        # since the letters are sorted in non-decreasing order, we can use a modified binary search.
        # in regular binary we check if the target is greater than mid, in modified we will see if it is greater or equal to mid because we want to find the smallest element greater than target
        # if the target is greater than mid, we will move to the right, else we will move to the left
        # in this way we will be able to keep a track of value which is greater than target and is the smallest
        low = 0
        high = len(letters)-1
        while low <= high:
            mid = low + (high-low)//2
            if target >= letters[mid]:
                low = mid+1
            else:
                high = mid-1
        return letters[low]
    
if __name__ == "__main__":
    letters = ["c", "f", "j"]
    target = "a"
    obj = Solution()
    out = obj.nextGreatestLetter(letters, target)
    print(out)