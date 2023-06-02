# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        size = 0
        temp = head
        while(temp):
            size+=1
            temp = temp.next
        if size == 1:
            return head
        if(size%2 == 0):
            mid = size//2
        else:
            mid = size//2 + 1

        while(head):
            if size == mid:
                break
            head = head.next
            size-=1
        return head