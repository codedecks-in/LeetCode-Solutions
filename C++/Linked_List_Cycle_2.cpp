/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //lets look at three pointers approach
        ListNode *slow = head, *fast = head;
        
        while(fast!=nullptr and fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        if(fast==nullptr || fast->next==nullptr){
            return nullptr;
        }
        ListNode* entry = head;
        while(entry != slow){
            slow = slow->next;
            entry = entry->next;
        }
        return slow; // or entry
    }
};
/*
- this algorithm requires two main steps
- the first one is to find the meeting point in the cycle (like in the case of detection of cycle)
- in the second step we move the slow pointer at the starting point and the entry pointer at the head one step each and the point they meet is the starting point of the cycle

- this can be proved by mathematics
- lets take distance of head to starting of cycle as l1
- and the distance of starting to the collision point as l2
- and the cycle length can be taken as c

lets see distances moved by both the pointers
- slowptr -> l1 + l2
- fastptr -> l1 + l2 + nC, here n is the abstract number of extra loops moved by fastptr
- also we know that fast pointer moves double than slow pointer 
=> 2*s = f
=> 2(l1 + l2) = l1 + l2 + nC
=> l1 + l2 = nC
=> l1 = nC - l2
this is the final equation we can see here 
this proves that the distance between the head and starting point of the cycle is equal to the distance between the collision point and the starting point of the cycle 
*/ 
