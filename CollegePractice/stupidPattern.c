#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    // to print a pattern like this
    // 4 4 4 4 4 4 4  
    // 4 3 3 3 3 3 4   
    // 4 3 2 2 2 3 4   
    // 4 3 2 1 2 3 4   
    // 4 3 2 2 2 3 4   
    // 4 3 3 3 3 3 4   
    // 4 4 4 4 4 4 4

    int n=0;
    scanf("%d", &n);
    int size = 2*n - 1;

    // for(int i=0; i<size; i++) {
    //     for(int j=0; j<size; j++) {
    //         int min = i < j ? i : j;
    //         min = min < size-i ? min : size-i-1;
    //         min = min < size-j-1 ? min : size-j-1;
    //         printf("%d ", n-min);
    //     }
    //     printf("\n");
    // }

    // another approach
    // for every next loop, we are reducing the number of same numbers to 2
    // like in first row there are 7 4's, in second row there are 5 3's and 2 4's
    // also this is a diagonal matrix
    
    int** pattern = (int**)malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++) {
        pattern[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size-i; j++)
        {
            for(int k=i; k<size-i; k++) {
                pattern[j][k] = n-i;
                pattern[k][j] = n-i;
            }
        }
        
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", pattern[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}