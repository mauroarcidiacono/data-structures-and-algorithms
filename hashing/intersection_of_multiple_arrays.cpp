// 2248. Intersection of Multiple Arrays
// https://leetcode.com/problems/intersection-of-multiple-arrays/description/
// Difficulty: Easy
// Strategy: hash map.
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> frequency;
        vector<int> answer;
        int n = nums.size();
        
        for (vector<int>& arr : nums) {
            for (int val : arr) {
                frequency[val] += 1;
            }
        }

        for (auto [key, val] : frequency) {
            if (val == n) {
                answer.push_back(key);
            }
        }
        sort(answer.begin(), answer.end());

        for (int item : answer) {
            cout << item << " ";
        }

        return answer;
    }
};

int main() {
    Solution sol;
    vector<vector <int>> nums = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
    sol.intersection(nums);
    
    return 0;
}