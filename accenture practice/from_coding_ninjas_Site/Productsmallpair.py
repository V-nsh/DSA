def Productsmallpair(sum, arr):
    if len(arr)<2:
        return -1
    arr = sorted(arr)
    hashMap = dict()
    for i in range(len(arr)):
        hashMap[arr[i]] = 1
    for i in range(len(arr)):
        num1 = arr[i]
        num2 = sum-num1
        if hashMap.get(num2) != None and num2+num1 <= sum:
            return num1*num2
    return 0

def productSmall(sum, arr):
    if len(arr)<2:
        return -1
    arr = sorted(arr)
    for i in range(1, len(arr)):
        if((arr[i]+arr[i-1]) <= sum):
            return arr[i]*arr[i-1]
    return 0

sum = int(input())
arr = list(map(int, input().split()))

print(productSmall(sum, arr))