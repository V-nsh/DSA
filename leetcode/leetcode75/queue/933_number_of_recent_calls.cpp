#include<iostream>
#include<queue>

using namespace std;

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
        
    }
    // this is pretty simple, you can only see the pings from time t-3000 since the counter frame can only see the pings in last 3000ms
    // for exampe if a ping happened at 1ms then the frame can see from -2999 to 1 and 1 frame has happened so far
    // for t=2 -2998 to 2, remember there was a ping at 1 so the arrayis [1, 2]
    // for ping at t=1000 -2900 to 100 [1, 2, 100]
    // but say t=3002, not it will only see the frame 2 to 3002 ie [2, 100, 3002].

    int ping(int t) {
        q.push(t);
        while(q.front() < (t-3000)) {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    RecentCounter rec;
    cout << rec.ping(1);
    cout << rec.ping(100);
    cout << rec.ping(3001);
    return 0;
}