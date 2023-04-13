#include<stdio.h>

using namespace std;

class Solution {
public:
    int binary_search(int arr[], int n, int k) {
        int left = 0, right = n, mid = left + (right-left)/2;

        while (left != right)
        {
            mid = left+(right-left)/2;

            if (arr[mid] == k)
            {
              return mid;
            }else if (arr[mid] < k)
            {
                left = mid+1;
            } else {
                right = mid-1;
            }
            
        }
        return -1;
    }
};