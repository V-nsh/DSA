#include<iostream>
#include<vector>

using namespace std;

class Peak {
public:
    int peakFinder(vector<int>& nums, int left, int right) {
        // Say we have an array [a....i] all numbered from 1 to 9, we can say b is a peak if and only if b>=a and b>=c, i is a peak if and only if i>=h.
        // Problem statement: Find a peak if it exists.
        // Question: Why do we have "if it exists" when we have greater than or equal to, if we had a different question like just greater than
        // Straight forward algorithm:
        // start from left for and array  1....n/2....n-1, n.
        // in case peak exists in the middle we look at n/2 elements so the worst case complexity will be theta of n. That is an order of n.
        // Now to optimize the problem we canuse a divide and conquer approach, and try to break the array into smaller ones.
        // Say we have an array:
        // 1, 2 .... n/2-1, n/2, n/2+1 .... n-1, n.
        // We look at n/2 and say we have a[n/2] < a[n/2-1] then we look only on the left half, that is from 1 ... n/2-1 for a peak
        //  else if(a[n/2+1] > a[n/2]) we only look towards right
        //  else we have found the solution at n/2.
        // so time complexity: say T(n) is the work done by algorithm on input size of n then
        // T(n) = T(n/2) + theta of 1,  theta of 1 because we take some constant time for comparisons.
        // so, base case : T(1) = theta(1)
        //  T(n) = theta(1) + .. + theta(1) <- logn times(base 2) = theta(log n)
        if (left==right)
        {
            return left;
        } else {
            int mid = (right+left)/2;
            int mid1 = mid+1;
            if (nums[mid] < nums[mid1])
            {
                return peakFinder(nums,  mid1, right);
            } else{
                return peakFinder(nums, left, mid);
            }   
        }
    }

public:
    int peakFinder_2D() {
        // an element is peak if and only if the elements on top, bottom, left and right of it ar smaller than the element.
        // Straight forward method: Greedy ascent
        // select an arbitrary direction and check if the next element is greater, if smaller or when we reach an edge, change direction towards next greatest.
        // In this approach we might end up visiting every element in the 2D array, so if we have an array m*n then the complexity will be theta(mn)
        // better solution:
        // pick middle columnj=m/2, find global maximum on column j at (i,j) and compare (i,j-1), (i,j), (i, j+1)
        // pick left columns if (i, j-1) > (i, j), that is the left half of the matrix
        // pick right if (i, j+1) > (i, j)
        // if (i, j) >= (i,j+1) && (i,j) >= (i,j-1) then (i,j) is the 2D peak.
        // if there's a single column, find the local maximum and that's the peak : base case.
    }
};

int main() {
    vector<int> nums = {2, 3, 6, 9, 4, 1, 4, 7, 10, 9};
    Peak pk;
    int ans  = pk.peakFinder(nums, 0, 9);
    cout << ans;

    return 0;
}