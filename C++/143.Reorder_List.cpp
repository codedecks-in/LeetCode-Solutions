/* medium difficulty */

class Solution {
public:
    void reorderList(ListNode* head) {

        //edge cases
        if ((!head) || (!head->next) || (!head->next->next)) return; 

        int l=0; //to calculate the length
        ListNode* curr=head;
        while(curr){
            l++;
            curr=curr->next;
        }

        //stack to store the second half of the elements of the ll
        stack<ListNode*> s;
        curr=head;

        //iterating till the end of the first half
        int m=(l+1)/2;
        while(m>=1){
            curr=curr->next;
            m--;
        }

        //pushing the second half of the elements in the stack
        while(curr){
            s.push(curr);
            curr=curr->next;
        }

        //attaching the elements from the top of the stack to the first half of the elements
        curr=head;
        while(curr&&!s.empty()){
            ListNode* temp=s.top();
            s.pop();
            temp->next=curr->next;
            curr->next=temp;
            curr=curr->next->next;
        }
        curr->next=NULL;
    }
};