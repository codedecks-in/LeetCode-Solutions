#Time Complexity: O(n)
#Space Complexity: O(1)

# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast =  head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
            
