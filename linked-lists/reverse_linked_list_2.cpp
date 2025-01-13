// 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/description/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* start = dummy; 

        for (int i = 1; i < left; i++) {
            start = start->next;
        }

        ListNode* curr = start->next;
        ListNode* prev = nullptr;
        for (int j = left; j <= right; j++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        start->next->next = curr;
        start->next = prev;

        return dummy->next;
    }
};

int main() {
    Solution sol;
    ListNode* n0 = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(5);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    ListNode* head = n0;

    sol.reverseBetween(head, 2, 4);

    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}