# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import queue
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        class ComparableNode:
            def __init__(self, node):
                self.node = node
            def __lt__(self, other):
                return self.node.val < other.node.val

        que = queue.PriorityQueue()
        for node in lists:
            if node is not None:
                que.put(ComparableNode(node))
        ret_node = ListNode(0)
        ret_next_node = ret_node
        while que.qsize() > 0:
            root_node = que.get()

            ret_next_node.next = ListNode(root_node.node.val)
            ret_next_node = ret_next_node.next

            if root_node.node.next is not None:
                que.put(ComparableNode(root_node.node.next))

        return ret_node.next
