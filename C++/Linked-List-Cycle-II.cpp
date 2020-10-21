
class Solution
{
	public:
		ListNode* detectCycle(ListNode *head)
		{
			//If head is null or head->next is null dont do anything just return.
			if (!head) return NULL;
			if (head->next == NULL) return NULL;
			//Take two pointers slow and fast both initially pointing to head .  
			ListNode *fast = head;
			ListNode *slow = head;
			while (fast and fast->next)
			{
				// Move fast pointer two step and slow pointer one step forward.
				fast = fast->next->next;
				slow = slow->next;
				//At some time if fast and slow are equal it means there is a cycle .
				if (fast == slow) break;
			}

			if (fast == NULL or fast->next == NULL) return NULL;
			//Now we point one pointer to head and increment both  the pointers one step untill slow and fast pointer do not become equal.
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			return slow;
		}
};