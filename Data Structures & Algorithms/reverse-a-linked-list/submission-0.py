# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None: return None
        if head.next == None: return head
        cur : ListNode  = head.next
        head.next = None
        prev : ListNode = head
        while (cur != None):
            next : ListNode = cur.next
            cur.next = prev
            prev = cur
            cur = next
            
        return prev