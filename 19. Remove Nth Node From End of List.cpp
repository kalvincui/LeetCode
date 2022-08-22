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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int size = 0;
        while (temp!=NULL){
            size++;
            temp = temp->next;
        }
        int index = size - n;
        if (index == 0){
            return head->next;
        }
        temp = head;
        ListNode *prev = temp;
        ListNode *next = temp->next;
        for (int i = 0; i<index; i++){
            prev = temp;
            temp = temp->next;
            next = temp->next;
        }
        prev -> next = next; 
        return head;
    }
};
