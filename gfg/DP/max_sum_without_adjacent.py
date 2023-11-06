#User function Template for python3
# https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
class Solution(object):
	
	def findMaxSum(self,arr, n):
		# this is a modified version of house robber problem
        # this is a modified version of Kadane's algorithm
		include, exclude = 0, 0
		for current in arr:
			new_include = exclude+current
			# the current element will never be included in next step as we are first finding the max of include and exclude and then assigning it to exclude
			new_exclude = max(include, exclude)
			# whatever we exclude in the previous step, we can include it in the current step
            # we are using include to ultimately find the next exclude
			include = new_include
			exclude = new_exclude
		return max(include, exclude)
	
if __name__=='__main__':
	arr = [3, 2, 7, 10]
	'''
	it 1:
	new_include = 0+3 = 3
	new_exclude = max(0, 0) = 0
	include = 3
	exclude = 0
	
	it 2:
	new_include = 0+2 = 2
	new_exclude = max(3, 0) = 3
	include = 2
	exclude = 3
	
	it 3:
	new_include = 3+7 = 10
	new_exclude = max(2, 3) = 3 ***
	include = 10
	exclude = 3
	
	it 4:
	new_include = 3+10 = 13
	new_exclude = max(10, 3) = 10
	include = 13
    exclude = 10
    '''
	arr = [3, 2, 5, 10, 7]
	'''
    it1:
    new_include = 0+3 = 3
    new_exclude = max(0, 0) = 0
    include = 3
    exclude = 0

    it2:
    new_include = 0+2 = 2
    new_exclude = max(3, 0) = 3
    include = 2
    exclude = 3

    it3:
    new_include = 3+5 = 8
    new_exclude = max(2, 3) = 3
    include = 8
    exclude = 3

    it4:
    new_include = 3+10 = 13
    new_exclude = max(8, 3) = 8
    include = 13
    exclude = 8

    it5:
    new_include = 8+7 = 15
    new_exclude = max(13, 8) = 13
    include = 15
    exclude = 13
    '''
	arr =  [5, 5, 10, 100, 10, 5]
	'''
    it1:
    new_include = 0+5 = 5
    new_exclude = max(0, 0) = 0
    include = 5
    exclude = 0

    it2:
    new_include = 0+5 = 5
    new_exclude = max(5, 0) = 5
    include = 5
    exclude = 5

    it3:
    new_include = 5+10 = 15
    new_exclude = max(5, 5) = 5
    include = 15
    exclude = 5

    it4:
    new_include = 5+100 = 105
    new_exclude = max(15, 5) = 15
    include = 105
    exclude = 15

    it5:
    new_include = 15+10 = 25
    new_exclude = max(105, 15) = 105
    include = 25
    exclude = 105

    it6:
    new_include = 105+5 = 110
    new_exclude = max(25, 105) = 105
    include = 110
    exclude = 105
    '''
	n = len(arr)
	ob = Solution()
	ans = ob.findMaxSum(arr, n)
	print(ans)