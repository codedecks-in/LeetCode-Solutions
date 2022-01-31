# https://leetcode.com/problems/merge-k-sorted-lists/
# Difficulty Level: Hard
# Tags: Math
# Time Complexity: O(log(n))
# Space Complexity: O(n)


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        if lists == []:
            return
        
        if len(lists) == 0:
            return []
        
        size = len(lists)
        
        def merge2(list1, list2):
            
            x = ListNode(0)
            y = x
            
            while (list1 and list2):
                
                if list1:
                    
                    if list1.val > list2.val:
                        
                        y.next = list2
                        list2 = list2.next
                        
                    else:
                        
                        y.next = list1
                        list1 = list1.next
                        
                    y = y.next
                    
                else:
                    
                    if list1.val < list2.val:
                        
                        y.next = list1
                        list2 = list1.next
                        
                    else:
                        
                        y.next = list2
                        list2 = list2.next
                        
                    y = y.next
                    
            if list1:
                
                y.next = list1
                
            elif list2:
                
                y.next = list2
                
            return x.next
        
        index = 1
        merged = lists[0]
        
        while (index < size):
            
            merged = merge2(merged, lists[index])
            index = index + 1
            
        return merged