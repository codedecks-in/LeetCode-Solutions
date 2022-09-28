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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*curr=head;
        
        while(curr!=NULL&&curr->next!=NULL)
        {
            ListNode*nex=curr->next;
            if(curr->val==nex->val)
                curr->next=nex->next;
             else
                 curr=nex;
        }
        return head;
    }
};
