#include <string>
#include <map>
#include <iostream>

using namespace std;

std::string specificOrder(std::string &x, std::string &y) {
    map<char, int> bucket;
    string ans;

    for(auto s: x){
        bucket[s]++;
    }

    for(auto b: y){
        if(bucket.find(b) != bucket.end()){
            // map: the target string that is to be sorted
            // key: the characters in the string
            // value: number of times the key appears
            string s(bucket.find(b)->second, b); //you can build strings like this (count, char)
            ans += s;
            bucket.erase(b);
        }
    }

    // add remaining to the answer string
    for (auto d: bucket){
        string s(d.second, d.first);
        ans += s;
    }

    // std::map<char, int>::iterator it = bucket.begin();

    // while(it != bucket.end()) {
    //     cout << "key: " << it->first << " value: " << it->second << "\n";
    //     ++it;
    // }

    return ans;
    
}

int main() {
    string s1, s2, res;
    s1 = "acabd";
    s2 = "abc";
    res = specificOrder(s1, s2);
    cout << res;
    return 0;
}