#include<algorithm>
#include<iostream>

using namespace std;

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        // int size = sizeof(A)/sizeof(A[0]);
        sort(A, A+n);
        int i, j;
        for(int k=0; k<n; k++){
           int target = X - A[k];
            i = k+1;
            j = n-1;
            while(i<j){
                int sum = A[i]+A[j];
                if(sum==target){
                    return true;
                } else if (sum>target) {
                    j--;
                } else {
                    i++;
                }
            }
        }
        return false;
    }

};

int main(){
    Solution sol;
    int A[] = {1,4, 45, 6, 10, 8};
    cout << sol.find3Numbers(A, 6, 11);

    return 0;
}