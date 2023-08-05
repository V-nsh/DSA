class Solution(object):
    def findDifferenceBrute(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """
        res = [[], []]
        for i in range(len(nums1)):
            if nums1[i] not in nums2 and (nums1[i] not in (nums1[:i]+nums1[i+1:])):
                res[0].append(nums1[i])
        for j in range(len(nums2)):
            if nums2[j] not in nums1 and (nums2[j] not in (nums2[:j]+nums2[j+1:])):
                res[1].append(nums2[j])
        return res
    
    def findDifference(self, nums1, nums2):
        map1 = dict()
        map2 = dict()
        res = [[], []]
        for i in range(len(nums1)):
            if map1.get(nums1[i])==None:
                map1[nums1[i]] = 0
            else:
                map1[nums1[i]] += 1
        for j in range(len(nums2)):
            if map2.get(nums2[j])==None:
                map2[nums2[j]] = 0
            else:
                map2[nums2[j]] += 1

        for i in map1:
            if map2.get(i)==None:
                res[0].append(i)
        for j in map2:
            if map1.get(j) == None:
                res[1].append(j)
        return res
        

if __name__=="__main__":
    # nums1 = [1,2,3]
    # nums2 = [2,4,6]
    nums1 = [1,2,3,3]
    nums2 = [1, 1, 2, 2]
    sol = Solution()
    print(sol.findDifference(nums1, nums2))