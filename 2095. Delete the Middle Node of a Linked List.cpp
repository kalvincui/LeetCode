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
    ListNode* deleteMiddle(ListNode* head) {
        int middle = 0;
        ListNode* temp = head;
        while (temp!=nullptr){
            temp = temp->next;
            middle++;
        }
        middle = middle/2;
        temp = head;
        int counter = 0;
        while (counter < middle-1){
            temp = temp->next;
            counter++;
        }
        if (temp->next != nullptr){
            temp->next = temp->next->next;
        }else {
            return nullptr;
        }
        return head;
    }
};
