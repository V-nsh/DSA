#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag;

        for (int j = 0; j < magazine.length(); j++)
        {
            if (mag.find(magazine[j] - 'a') == mag.end())
            {
                mag.insert(make_pair(magazine[j] - 'a', 1));
            }
            else
            {
                mag[magazine[j] - 'a']++;
            }
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {

            if (mag[ransomNote[i] - 'a'] == 0)
            {
                return false;
            }
            else
            {
                mag[ransomNote[i] - 'a']--;
            }
        }
        return true;
    }
};