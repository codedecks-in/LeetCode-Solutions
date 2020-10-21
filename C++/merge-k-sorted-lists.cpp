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
	//Fucntion to append node at the end of lisked list
    struct ListNode *begg(struct ListNode *head, int x){
        struct ListNode *temp = new ListNode(x);
        //If there is no node
        if(head==NULL){
            head=temp;
            return head;
        }
        //If nodes already present
        struct ListNode *ptr=head;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=temp;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	//Using multiset s it will allow duplicate values and will store them in sorted order.
        multiset<int> s;
        //Adding values to multiset.
        for(int i=0;i<lists.size();i++){
            ListNode *p1=lists[i];
            while(p1){
                s.insert(p1->val);
                p1=p1->next;
            }
        }
        //Initializing the head of linked list.
        struct ListNode *head2=NULL;
        //Appending nodes in the linked list from multiset.
        for(auto it=s.begin();it!=s.end();++it){
            head2=begg(head2,*it);
            cout<<*it<<" ";
        }
        return head2;
    }
};
