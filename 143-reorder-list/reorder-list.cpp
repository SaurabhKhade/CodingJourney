/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast=head->next;

        while (fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow ->next;
        slow ->next =NULL;

        ListNode* prev = NULL;

        while (head2 != NULL) {
            ListNode* front = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = front;
        }

        head2 = prev;
        ListNode* temp = head;

        while (temp!=NULL && head2!=NULL) {
            ListNode* front = head2;
            head2 = head2->next;
            front->next = temp->next;
            temp->next = front;
            temp = temp->next->next;
        }
    }
};