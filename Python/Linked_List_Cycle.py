#Time: 95.48%
#Space: 99.98%
#Difficulty: Easy
#Acceptance: 49.0%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # Return False if the list is empty or has only one node (no cycle possible)
        if not head or not head.next:
            return False
        
        # Initialize two pointers: 'slow' moves one step at a time, 'fast' moves two steps
        slow = head
        fast = head.next

        # Iterate through the list
        while slow != fast:
            # If 'fast' reaches the end of the list (or its next step is None), there's no cycle
            if not fast or not fast.next:
                return False

            # Move 'slow' one step forward and 'fast' two steps forward
            slow = slow.next
            fast = fast.next.next

        # If 'slow' and 'fast' meet, there is a cycle in the list
        return True
