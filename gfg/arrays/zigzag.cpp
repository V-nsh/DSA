#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
// Given an array arr of distinct elements of size N, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form: 
// think of even elements as small and odd elements as big.
    void zigZag(int arr[], int n) {
        for (int i = 1; i < n-1; i++)
        {
            if (i%2==1)
            {
                if ((arr[i] < arr[i-1]) || (arr[i] < arr[i+1]))
                {
                    if (arr[i-1] > arr[i+1])
                    {
                        swap(arr[i], arr[i-1]);
                    } else {
                        swap(arr[i], arr[i+1]);
                    }
                    
                }
                
            } else {
                if ((arr[i] > arr[i-1]) || (arr[i] > arr[i+1]))
                {
                    if (arr[i-1] < arr[i+1])
                    {
                        swap(arr[i], arr[i-1]);
                    } else {
                        swap(arr[i], arr[i+1]);
                    }
                    
                }
            }
            
        }
        
    }
};

int main() {
    Solution sol;
    int arr[] = {4, 3, 7, 8, 6, 2, 1};
    sol.zigZag(arr, 7);

    for(auto i: arr) {
        std::cout << i;
    }   
}