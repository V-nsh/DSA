#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>

using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<string>> keyVal;
    unordered_map<string, vector<int>> keyTime;

    // method 2
    unordered_map<string, vector<pair<int, string>>> key_TimeVal;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyVal[key].push_back(value);
        keyTime[key].push_back(timestamp);
        key_TimeVal[key].emplace_back(timestamp, value);
    }
    
    // memory limit exceeded.
    string get(string key, int timestamp) {
        string res = "";
        if(keyVal.find(key) == keyVal.end()) {
            return "";
        }
        // vector<int> timeArr = keyTime[key];
        int left = 0, right = key_TimeVal[key].size()-1, mid = 0;

        while(left <= right) {
            mid = left + (right-left)/2;
            if (key_TimeVal[key][mid].first > timestamp)
            {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        if(left>0) {
            res = key_TimeVal[key][left - 1].second;
        } else {
            res = key_TimeVal[key][0].second;
        }
        return res;
    }

    string getMem(string key, int timestamp) {
        if (key_TimeVal.find(key) == key_TimeVal.end())
        {
            return "";
        }
        vector<pair<int, string>> pairs = key_TimeVal[key];        
        auto first = pairs.begin(), last = pairs.end();
        string res = "";
        
        while (first != last) {
            auto mid = first + distance(first, last)/2;
            if(mid->first <= timestamp) {
                res = mid->second;
                first = mid+1;
            } else {
                last = mid-1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int  main() {
    TimeMap* timeMap = new TimeMap();
    
    // // Test case
    // timeMap->set("foo", "bar", 1);
    // cout << timeMap->get("foo", 1) << endl;    // Output: "bar"
    // cout << timeMap->get("foo", 3) << endl;    // Output: "bar"
    
    // timeMap->set("foo", "bar2", 4);
    // cout << timeMap->get("foo", 4) << endl;    // Output: "bar2"
    // cout << timeMap->get("foo", 5) << endl;    // Output: "bar2"

    // Test case
    timeMap->set("love", "high", 10);
    timeMap->set("love", "low", 20);
    
    cout << timeMap->getMem("love", 5) << endl;    // Output: ""
    cout << timeMap->getMem("love", 10) << endl;   // Output: "high"
    cout << timeMap->getMem("love", 15) << endl;   // Output: "high"
    cout << timeMap->getMem("love", 20) << endl;   // Output: "low"
    cout << timeMap->getMem("love", 25) << endl;   // Output: "low"
    
    // Cleanup
    delete timeMap;

    return 0;
}