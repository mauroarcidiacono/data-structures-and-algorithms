// 1426. Counting Elements
// https://leetcode.com/problems/counting-elements/description/
// Difficulty: Easy
// Strategy: unordered set.
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0;
        unordered_set<int> arr_set(arr.begin(), arr.end());

        for (int num : arr) {
            if (arr_set.find(num + 1) != arr_set.end()){
                count += 1;
            }
        }
        cout << count << '\n';
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,1,3,3,5,5,7,7};
    sol.countElements(arr);
    return 0;
}
