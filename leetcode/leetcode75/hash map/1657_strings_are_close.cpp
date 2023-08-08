#include<string>
#include<map>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // since we can rearrange, just the frequencies must match.
        // set<char> w1, w2; //vectors are better than sets.
        vector<int> v1(26, 0), v2(26, 0), w1(26, 0), w2(26, 0);
        for (auto i: word1){
            w1[i-'a']=1;
            // if set use:
            // w1.insert(i)
            v1[i-'a']++;
        }

        for (auto j: word2){
            w2[j-'a']=1;
            //similarly:
            //w2.insert(j)
            v2[j-'a']++;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return w1==w2 && v1==v2;
    }
};

int main(){
    Solution sol;
    string word1 = "abc";
    string word2 = "acb";

    cout << sol.closeStrings(word1, word2);

    return 0;
}