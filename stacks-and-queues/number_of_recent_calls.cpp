// 933. Number of Recent Calls
// https://leetcode.com/problems/number-of-recent-calls/description/
// Difficulty: Easy
// Strategy: queue.

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
    }
    
    int ping(int t) {
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    RecentCounter* obj = new RecentCounter();
    vector<int> v{1, 100, 3001, 3002};

    for (int n : v) {
        cout << obj->ping(n) << '\n';
    }
}