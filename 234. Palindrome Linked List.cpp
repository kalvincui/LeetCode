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
    bool isPalindrome(ListNode* head) {
        //Find Middle node (fast and slow pointers)
        //Reverse Linked List From Middle Node
        //Compare the two lists
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = reverseList(slow);
        return Palindromic (head, head2);
    }
    ListNode* reverseList (ListNode* head){
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
    bool Palindromic (ListNode* head, ListNode* head2){
        if (head == NULL || head2 == NULL){
            return true;
        }
        if (head->val == head2->val){
            return Palindromic (head->next, head2->next);
        }
        return false;
    }
};
