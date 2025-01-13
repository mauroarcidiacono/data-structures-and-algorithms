// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/description/
// Difficulty: Medium
// Strategy: manipulation of linked list pointers.

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* dummy = head->next;
        ListNode* prev = nullptr;
        
        while (head != nullptr && head->next != nullptr) {
            ListNode* nextNode = head->next->next;
            if (prev != nullptr) {
                prev->next = head->next;
            }
            prev = head;
            
            head->next->next = head;
            head->next = nextNode;

            head = nextNode;
        }

        return dummy;
    }
};

int main() {
    Solution sol;
    ListNode* n0 = new ListNode(0);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    ListNode* head = n0;

    ListNode* temp = sol.swapPairs(head);

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}