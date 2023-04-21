#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()){
            return false;
        }
        
        unordered_map<char, int> sAn;

        for (int i = 0; i < s.length(); i++)
        {
            if (sAn.find(s[i] - 'a') == sAn.end())
            {
                sAn.insert(make_pair(s[i] - 'a', 1));
            }
            else
            {
                sAn[s[i] - 'a']++;
            }
        }

        for (int j = 0; j < t.length(); j++)
        {
            if (sAn[t[j] - 'a'] == 0)
            {
                return false;
            }
            else
            {
                sAn[t[j] - 'a']--;
            }
        }
        return true;
    }
};