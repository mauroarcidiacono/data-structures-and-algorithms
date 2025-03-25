// 496. Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/description/
// Difficulty: Easy
// Strategy: hash map and stack.
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> stck;
            vector<int> ans(nums1.size(), 0);
            unordered_map<int, int> umap;

            for (int i = 0; i < nums2.size(); i++) {
                while (!stck.empty() && nums2[i] > stck.top()) {
                    umap[stck.top()] = nums2[i]; 
                    stck.pop();
                }
                stck.push(nums2[i]);
            }
            
            for (int i = 0; i < nums1.size(); i++) {
                if (umap.find(nums1[i]) != umap.end()) {
                    ans[i] = umap[nums1[i]];
                } else {
                    ans[i] = -1;
                }
            }
            for (int el : ans) {
                cout << el << ' ';
            }
            return ans;
        }
};

int main() {
    Solution sol;
    // vector<int> nums1{4, 1, 2};
    // vector<int> nums2{1, 3, 4, 2};
    vector<int> nums1{2, 4};
    vector<int> nums2{1, 2, 3, 4};
    sol.nextGreaterElement(nums1, nums2);
    return 0;
}

