# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        """
        Approach:
        - Use a dummy node to handle edge cases (like swapping at head).
        - Initialize 'prev' pointer at dummy.
        - Traverse the list in pairs (first, second).
        - Swap nodes by reassigning next pointers:
            prev -> second -> first -> next_pair
        - Move 'prev' two nodes ahead and continue.

        Intuition:
        - We are not modifying node values, only connections.
        - Swapping nodes in a linked list requires careful pointer manipulation.
        
        Time Complexity: O(n), n = number of nodes, as we traverse each node once.
        Space Complexity: O(1), we only use a few pointers.
        """
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        
        while prev.next and prev.next.next:
            first = prev.next
            second = prev.next.next

            # Swapping
            first.next = second.next
            second.next = first
            prev.next = second

            # Move prev pointer two nodes ahead
            prev = first
        
        return dummy.next
