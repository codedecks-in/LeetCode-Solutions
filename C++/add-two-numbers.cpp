/*
- Add Two Numbers -
Difficulty: Medium
Time Complexity: O(n)
Space Complexity: O(n)
*/

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
	//create ListNode* that will point to first digit of result
        ListNode* result = new ListNode();

	//create vars to store the vals of the current nodes that we are adding
	//because adding one-digit vals can produce results with two-digits, create carry var to store the value we are carrying over to the next addition
        int op1 = l1->val, op2 = l2->val, carry = 0, res = op1 + op2 + carry;

	//checking if result of first addition is > 9
        if((res / 10) == 1)
        {
            //if so result that gets stored in current digit found with modulus operator and carry is set to 1
	    res = res % 10;
            carry = 1;
        }
	//setting val of first digit of result
        result->val = res;

	//creating new ListNode* that will point to the resulting digit of each addition along the way
        ListNode* sum = result;

	//loop as long as either the first operand has another digit to add, the second operand has another digit to add, or the final addition resulted in a carry
        while(l1->next != nullptr || l2->next != nullptr || carry == 1)
        {
            op1 = 0, op2 = 0, res = 0;
            //sets vals of operands to their next value if they exist
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

	    //creating new ListNode* to point to the next digit of result and points the sum pointer to it
            ListNode* temp = new ListNode(res);
            sum->next = temp;
            sum = sum->next;
        }
        return result;
    }
};
