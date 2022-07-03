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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode head;
        ListNode *temp = &head;
        while (l1!=NULL || l2!=NULL){
            int val = carry;
            if (l1!=NULL){
                val+=l1->val;
                l1 = l1->next;
            }
            if (l2!=NULL){
                val+=l2->val;
                l2=l2->next;
            }
            temp->next = new ListNode (val%10);
            temp = temp->next;
            carry = val / 10;
        }
        if (carry!=0){
            temp->next = new ListNode(carry);
        }
        return head.next;
    }
};
