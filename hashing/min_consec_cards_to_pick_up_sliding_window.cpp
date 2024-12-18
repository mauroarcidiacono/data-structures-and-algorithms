// 2260. Minimum Consecutive Cards to Pick Up
// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/
// Difficulty: Medium
// Strategy: sliding window and unordered set.
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_set<int> seen;
        int left = 0, right = 0;
        int ans = INT_MAX; 

        while (right < cards.size()) {
            if (seen.find(cards[right]) == seen.end()) {
                seen.insert(cards[right]);
            } else {
                while (seen.find(cards[right]) != seen.end()) {
                    seen.erase(cards[left]);
                    left++;
                }
                ans = min(ans, right - left + 2);
                seen.insert(cards[right]);
                
            }
            right++;
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