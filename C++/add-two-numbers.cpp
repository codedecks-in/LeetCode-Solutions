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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* result = new ListNode();

        int op1 = l1->val, op2 = l2->val, carry = 0, res = op1 + op2 + carry;
        if((res / 10) == 1)
        {
            res = res % 10;
            carry = 1;
        }
        result->val = res;

        ListNode* sum = result;
        while(l1->next != nullptr || l2->next != nullptr || carry == 1)
        {
            op1 = 0, op2 = 0, res = 0;
            if(l1->next != nullptr)
            {
                l1 = l1->next;
                op1 = l1->val;
            }
            if(l2->next != nullptr)
            {
                l2 = l2->next;
                op2 = l2->val;
            }
            res = op1 + op2 + carry;
            if((res / 10) == 1)
            {
                res = res % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            ListNode* temp = new ListNode(res);
            sum->next = temp;
            sum = sum->next;
        }
        return result;
    }
};
