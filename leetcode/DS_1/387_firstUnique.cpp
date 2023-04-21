#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> alpha;
        int ind = s.size();
        int i;
        for (i = 0; i < s.length(); i++)
        {
            if (alpha.find(s[i]) == alpha.end())
            {
                alpha.insert(make_pair(s[i], make_pair(i, 1)));
            }
            else
            {
                alpha[s[i]].second++;
            }
        }
        for (auto p : alpha)
        {
            if ((p.second).second == 1)
            {
                ind = min((p.second).first, ind);
            }
        }
        if (ind != s.size())
        {
            return ind;
        }
        return -1;
    }
};