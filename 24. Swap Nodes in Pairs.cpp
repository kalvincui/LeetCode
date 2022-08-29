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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode * temp = head;
        ListNode * node1 = temp;
        ListNode * node2 = temp -> next;
        ListNode * node3 = temp->next->next;
        node2 -> next = node1;
        head = node2;
        node1 -> next = node3;
        temp = node3;
        ListNode * prev = node1;
                
        while (temp !=NULL && temp->next !=NULL){
            node1 = temp;
            node2 = temp -> next;
            node3 = temp->next->next;
            node2 -> next = node1;
            node1 -> next = node3;
            temp = node3;
            prev -> next = node2;
            prev = node1;
        }
        return head;
    }
};
