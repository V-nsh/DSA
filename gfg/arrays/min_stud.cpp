#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    // This can be solved using longest increasing subsequence DP and DFS(brute force).
    // just subtract the subsequence from total and voila! 
    // N^2 solution.
public:
    int removeStudents(int H[], int N) {
        vector<int> cache(N, 1);
        for (int i = N-1; i >= 0; i--)
        {
            for (int j = i+1; j < N; j++)
            {
                if (H[i] < H[j])
                {
                    cache[i] = std::max(cache[i], 1+cache[j]);
                }
                
            }
        }
        return N-(*max_element(cache.begin(), cache.end())); //only for gfg, remove N- and it will give the LIS.
    }

    // greedy approach using binary search:
    // what we are doing in LIS is essentially replacing the next non fitting value by the one just greater than the number. Eg:
    // nums = [2,6,8,3,4,5,1]
    // now with DP we get these solutions:
    // 1 = [2,6,8], 2 = [2,3,4,5], 3 = [1]
    // when we cam across 3, we could not put it in subset 1, because 3 is smaller than 8, but to optimize we can just keep one set and replace it with 6.
    // We can do this because we know number greater than 6 after 6 is only 8. So replacing with 6 we get [2,3,8], then we come across 4, number just greater than 4 is 8, so replace.
    // Now we have [2,3,4] and we come across 5, we simply push 5. [2,3,4,5], now we come across 1, the algorithm will replace 2 with 1 but this will not be a problem.

public:
    int just_big(vector<int>& nums, int end, int target) {
        int start = 0;
        int max = -1;

        while (start <= end)
        {
            int mid = start+(end-start)/2;
            if (nums[mid] >= target)
            {
                max = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return max;
    }

public:
    int remove_students_greedy(int H[], int N) {
        vector<int> seq;
        for (int i = 0; i < N; i++)
        {
            if (seq.empty() || seq[seq.size()-1] < H[i])
            {
                seq.push_back(H[i]);
            } else {
                auto ind = just_big(seq, distance(seq.begin(), seq.end()), H[i]);
                seq[ind] = H[i];
            }
        }
        return seq.size();
    }
};

int main() {
    Solution sol;
    int H[] = {9, 1, 2, 3, 1, 5};
    int lis = sol.remove_students_greedy(H, 6);
    std::cout << lis;
    return 0;
}