#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    /*
    brutal than the brute force built by brute bayne.
    first I sort, then insert the same, with index, in a map that has the sorted string and a list of indices and a copy of og because we're sorting the original and a solution vector of vectors.
    this is bizzare.
    time: O(MNlogN) where M is the length of strs and N is the average length of string in strs.
    space: yes. (it's O(M+M+M+...sizeof the map times M))
    */
    vector<vector<string>> groupAnagramsSorting(vector<string>& strs) {
        vector<vector<string>> sol;
        vector<string> og = strs;
        unordered_map<string, vector<string>> map;

        for(int i = 0; i<strs.size(); i++) {
            sort(strs[i].begin(), strs[i].end());
            if(map.find(strs[i]) == map.end()) {
                // vector<int> temp1;
                // temp1.push_back(i);
                map.insert({strs[i], {og[i]}});
            } else {
                map[strs[i]].push_back(og[i]);
            }
        }

        // for(int i  = 0; i<strs.size(); i++) {
        //     vector<string> temp;
        //     while(!map[strs[i]].empty()) {
        //         int current = map[strs[i]].back();
        //         temp.push_back(og[current]);
        //         map[strs[i]].pop_back();
        //     }
            
        //     if(temp.size() > 0){sol.push_back(temp);}
        // }

        for(auto& it : map) {
            sol.push_back(it.second);
        }

        // for(auto it : og) {
        //     cout << it << endl;
        // }

        return sol;
    }

public:
    struct VectorHasher {
        size_t operator()(const vector<int>& V) const {
            size_t hash = V.size();
            for (auto i : V)
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            return hash;
        }
    };

public:
    /*
    say we have a list of alphabets of length 26, and for a word like abc the list will be something like [1, 1, 1, 0...] 23 0s
    the idea is to have a hashmap with this list as key, and for this key add all the words that match the key.
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> alphabets(26, 0);
        unordered_map<vector<int>, vector<string>, VectorHasher> map;
        vector<vector<string>> sol;
        for(int i = 0; i<strs.size(); i++) {
            vector<int> temp = alphabets;
            for(auto it: strs[i]) {
                temp[it-'a']++;
            }
            if(map.find(temp) == map.end()) {
                map.insert({temp, {strs[i]}});
            } else {
                map[temp].push_back(strs[i]);
            }
        }

        for(auto& it: map) {
            sol.push_back(it.second);
        }

        return sol;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution sol;
    vector<vector<string>> res;
    res = sol.groupAnagramsSorting(strs);
    for(auto it : res) {
        for(auto it1 : it) {
            cout << it1 << endl;
        }
    }
    return 0;
}