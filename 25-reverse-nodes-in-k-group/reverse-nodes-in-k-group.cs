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
    public ListNode ReverseKGroup(ListNode head, int k) {
        var temp = head;
        int cnt = k-1;
        while (temp != null && cnt > 0) {
            temp = temp.next;
            cnt--;
        }

        if (temp == null) return head;

        var prev = ReverseKGroup(temp.next, k);
        temp.next = null;

        while (head != null) {
            var front = head.next;
            head.next = prev;
            prev = head;
            head = front;
        }

        return prev;
    }
}