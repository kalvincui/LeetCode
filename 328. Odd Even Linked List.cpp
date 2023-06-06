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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        ListNode * oddhead = head;
        ListNode * evenhead = head->next;
        ListNode * oddtemp = oddhead;
        ListNode * eventemp = evenhead;
        while (oddtemp->next!=nullptr && eventemp->next!=nullptr){
            oddtemp -> next = eventemp->next;
            oddtemp = oddtemp->next;
            eventemp->next = oddtemp->next;
            eventemp = eventemp->next; 
        }
        oddtemp->next = evenhead;
        return oddhead;
    }
};
