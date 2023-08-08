#include<iostream>
#include<map>
#include<string>

using namespace std;

// also see: CarTrade Practice\coding ninjas\customSortString.cpp

class Solution {
public:
    string customSortString(string order, string s) {
    map<char, int> bucket;
    string ans;

    for(auto a: s){
        bucket[a]++;
    }

    for(auto b: order){
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

    return ans;
    }
};