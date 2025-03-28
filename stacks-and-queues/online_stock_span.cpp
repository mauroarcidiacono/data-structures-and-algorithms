// 901. Online Stock Span
// https://leetcode.com/problems/online-stock-span/description/
// Difficulty: Medium
// Strategy: monotonic stack.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StockSpanner {
    public:
        stack<pair<int, int>> stk;

        StockSpanner() {}
        
        int next(int price) {
            int span = 1;
            while (!stk.empty() && stk.top().first <= price) {
                span += stk.top().second;
                stk.pop();
            }
            stk.push({price, span});
            return span;
        }
    };
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */

int main() {
    StockSpanner* stockSpanner = new StockSpanner();
    vector<int> dailyPrice{100, 80, 60, 70, 60, 75, 85};
    for (int el : dailyPrice) {
        int temp = stockSpanner->next(el);
        cout << temp << ' ';
    }
    return 0;
}