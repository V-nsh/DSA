#include<string>
#include<unordered_map>
#include<iostream>
#include<typeinfo>
#include<algorithm>

using namespace std;

class Solution {
public:
    /*
    the idea is to make a map and store the number of times each char occurs, 
    if the chars match for both strings they're anagrams.
    Time: O(S+T)
    Space: O(S)
    */
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> map;
        for(int i = 0; i<s.length(); i++) {
            if(map.find(s[i]) == map.end()) {
                map.insert({s[i], 1}); // the current char hasn't been seen yet.
            } else {
                map[s[i]]++; //already exists so increase by 1.
            }
        }

        for(int i=0; i<t.length(); i++) {
            if((map.find(t[i])==map.end()) || map[t[i]] == 0) { //either  the char in t is not present in s if not in map, or the count is more in t.
                return false;
            } else {
                map[t[i]]--; // if there's a match we use that char.
            }
        }

        return true;
    }

public:
    /*
    Time: O(NlogN)
    Space: sorting algos do take O(N) space but some interviews consider O(1) ie constant(according to neetcode).
    idea: just sort and use a == operator lmao
    */
    bool isAnagramNlogN(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};


int main() {
    Solution sol;
    string s = "something is here";
    cout << typeid(s[1]).name() << endl;
    string q = "anagram", t = "nagaram";
    cout << sol.isAnagramNlogN(q, t);
    return 0;
}
