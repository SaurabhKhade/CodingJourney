/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        var head = new ListNode();
        var temp = head;
        var queue = new PriorityQueue<ListNode, int>();

        foreach (var list in lists) {
            if (list != null) {
                queue.Enqueue(list, list.val);
            }
        }

        while (queue.Count > 0) {
            var top = queue.Dequeue();
            temp.next = top;
            temp = temp.next;
            
            if (top.next != null) {
                queue.Enqueue(top.next, top.next.val);
            }
        }

        return head.next;
    }
}