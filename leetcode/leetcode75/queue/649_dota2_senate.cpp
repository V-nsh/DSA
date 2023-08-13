#include<string>
#include<queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad;
        queue<int> dire;
        int n = senate.length();
        // thinking of queue if we had something like RRDDD, first we might think oh Dires are more in number so they win
        // but there can be multiple rounds, first two radiants will element the first two Dires and move to the back of the queue
        // thus the queue becomes DRR, but there's just one Dire left which can only eleminate one Radiant, leaving one Radiant in queue.
        
        // thus the idea is to create 2 queues of dires and radiants that contain the index of their position in the string
        for (int i = 0; i < n; i++)
        {
            if (senate[i]=='R')
            {
                rad.push(i);
            } else {
                dire.push(i);
            }
        }

        // lower position means higher priority since they came first in string.
        while(!rad.empty() && !dire.empty()) {
            if (rad.front() < dire.front())
            {
                int toKeep = rad.front() + n;
                rad.pop();
                // then we push the senate that is allowed to stay after the ith round back to the queue with an offset of n
                // this means in the next round the order will be maintained and those who are supposed to be kicked will go away
                rad.push(toKeep);
                dire.pop();
            } else {
                int toKeepDir  = dire.front()+n;
                dire.pop();
                dire.push(toKeepDir);
                rad.pop();
            }
        }
        
        return rad.size()==1 ? "Radiant" : "Dire";
        
    }
};