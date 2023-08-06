def LargeSmallSum(arr):
    # mergeSort(arr, 0, len(arr))
    # return arr
    evens, odds = [], []
    for i in range(len(arr)):
        if i%2==0:
            evens.append(arr[i])
        else:
            odds.append(arr[i])
    odds = sorted(odds)
    evens = sorted(evens)
    secondSmallest = odds[1]
    secondLargest = evens[-2]
    return secondSmallest+secondLargest

def mergeSort(arr, left, right):
    if left < right - 1:
        mid = left + (right - left) // 2
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)
        merge(arr, left, mid, right)

def merge(arr, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    leftArr, rightArr = [], []
    for i in range(n1):
        leftArr.append(arr[left + i])
    for j in range(n2):
        rightArr.append(arr[mid + j])

    i, j, k = 0, 0, left
    while i < n1 and j < n2:
        if leftArr[i] <= rightArr[j]:
            arr[k] = leftArr[i]
            i += 1
        else:
            arr[k] = rightArr[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = leftArr[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = rightArr[j]
        j += 1
        k += 1


arr = list((map(int, input().split())))
print(LargeSmallSum(arr))
