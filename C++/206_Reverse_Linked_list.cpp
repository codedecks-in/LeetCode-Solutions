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
class Solution {
public:
    ListNode* reverse(ListNode *head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode *newHead = reverse(head -> next);
        if(head -> next != NULL) head -> next -> next = head;
        head -> next = NULL;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
};

//Complexity Analysis
// Time Complexity - O(n)
//Space Complexity - O(1)