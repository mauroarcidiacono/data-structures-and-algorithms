// 2130. Maximum Twin Sum of a Linked List
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
// Difficulty: Medium
// Strategy: reversal of a linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head; 
        ListNode* fast = head; 

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now the middle of the linked list.

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // prev is now the head of the reversed linked list
        int solution = 0;
        while (prev != nullptr) {
            solution = max(solution, prev->val + head->val);
            prev = prev->next;
            head = head->next;
        }
        
        return solution;
    }
};

int main() {
    Solution sol;
    ListNode* n0 = new ListNode(4);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    ListNode* head = n0;

    int s = sol.pairSum(head);

    cout << s << '\n';

    return 0;
}