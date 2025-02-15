// 346. Moving Average From Data Stream
// https://leetcode.com/problems/moving-average-from-data-stream/description/
// Difficulty: Easy
// Strategy: queue.

#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
public:
    queue<int> q;
    int s;
    double sum;

    MovingAverage(int size) {
        s = size;
        sum = 0;
    }
    
    double next(int val) {
        if (q.size() > s - 1) {
            sum -= q.front();
            q.pop();
        }

        q.push(val);

        return (sum += val) / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main() {
    int size = 3;
    MovingAverage* obj = new MovingAverage(size);
    vector<int> v{1, 10, 3, 5};

    for (int n : v) {
        cout << obj->next(n) << '\n';
    }
}