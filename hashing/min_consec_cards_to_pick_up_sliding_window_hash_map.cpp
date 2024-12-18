// 2260. Minimum Consecutive Cards to Pick Up
// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/
// Difficulty: Medium
// Strategy: hash map.
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> freq; // num : pos
        int ans = INT_MAX;

        for (int i = 0; i < cards.size(); i++){
            if (freq.find(cards[i]) != freq.end()) {
                ans = min(ans, i - freq[cards[i]] + 1);
            }
            
            freq[cards[i]] = i;
        }
        cout << ((ans == INT_MAX) ? -1 : ans) << '\n';
        return (ans == INT_MAX) ? -1 : ans;
    }
};


int main() {
    Solution sol;
    vector<int> card0 = {3,4,2,3,4,7};
    vector<int> card1 = {1,0,5,3};
    vector<int> card2 = {3,4,2,9,4,7};
    vector<int> card3 = {2,1,2,1,1};
    sol.minimumCardPickup(card0);
    sol.minimumCardPickup(card1);
    sol.minimumCardPickup(card2);
    sol.minimumCardPickup(card3);
    return 0;
}