#include <vector>
#include <map>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> hashMap;
        unordered_set<int> set;
        for(int i: arr){
            hashMap[i]++;
        }

        for(auto it: hashMap) {
            cout << "key: " << it.first << " value: " << it.second <<"\n";
        }
        
        for(auto i: hashMap){
            if(set.find(i.second) != set.end()){
                return false;
            }
            set.insert(i.second);
        }

        return true;
    }
};

int main() {
    vector<int> arr = {1,2,2,1,1,3};
    Solution sol;
    cout << sol.uniqueOccurrences(arr);
    return 0;
}