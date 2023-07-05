class Sorting(object):
    def insertionSort(self, arr):
        for j in range(1, len(arr)):
            key = arr[j]
            i = j-1
            while(i>=0 and arr[i] > key):
                arr[i+1] = arr[i]
                i -= 1
            arr[i+1] = key

if __name__=='__main__':
    s = Sorting()
    arr = [1, 5, 3, 4]
    s.insertionSort(arr)
    print(arr)