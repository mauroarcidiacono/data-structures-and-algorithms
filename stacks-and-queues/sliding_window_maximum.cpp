// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/description/
// Difficulty: Hard.
// Strategy: monotonic stack.
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> answer;
            deque<int> deq;

            for (int i = 0; i < nums.size(); i++) {

                while (!deq.empty() && nums[i] > nums[deq.back()]) {
                    deq.pop_back();
                }

                deq.push_back(i);

                if (deq.front() + k == i) {
                    deq.pop_front();
                }
                
                if (i >= k - 1) {
                    answer.push_back(nums[deq.front()]);
                }
            }
            
            for (int val : answer) {
                cout << val << " ";
            }
            return answer;
        }
    };

int main() {
    Solution sol;
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    // vector<int> nums{1, -1};
    // int k = 1;
    sol.maxSlidingWindow(nums, k);
    return 0;
}
