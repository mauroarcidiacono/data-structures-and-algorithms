// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/description/
// Difficulty: Medium
// Strategy: hash map.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> counts;
        vector<vector<string>> ans;
        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            counts[temp].push_back(s);
        }

        for (auto& [key, val] : counts) {
            ans.push_back(val);
        }
        
        for (vector v : ans) {
            cout << "{ ";
            for (string st : v) {
                cout << st << " ";
            }
            cout << "} ";
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<string> strs = {"a"};
    sol.groupAnagrams(strs);
    return 0;
}