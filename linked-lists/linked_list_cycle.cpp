// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/description/
// Difficulty: Easy
// Strategy: fast and slow pointers.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << "true" << '\n';
                return true;
            }
        }
        cout << "false" << '\n';
        return false;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(-1);
    ListNode* n0 = new ListNode(3);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(0);
    ListNode* n3 = new ListNode(-4);

    head->next = n0;
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    sol.hasCycle(head);
}