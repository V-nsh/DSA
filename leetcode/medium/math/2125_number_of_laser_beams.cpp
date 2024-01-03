#include<vector>
#include<string>

using namespace std;

class Solution {
    /*
    the idea is simple, number of bonds between lasers of curr row and next row is the number of lasers in curr * number of lasers in next.
    */
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;
        for(auto b : bank) {
            int count  = 0;
            for(int i : b) {
                if(i=='1') {
                    count++;
                }
            }
            if(count) {
                ans += count * prev;
                prev = count;
            }
        }

        return ans;
    }
};