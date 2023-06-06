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
    int pairSum(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        vector <int> numbers;
        while (temp!=NULL){
            numbers.push_back(temp->val);
            temp = temp->next;
            size++;
        }
        int sum = 0;
        temp = head;
        int idx = 0;
        while (idx<size){
            sum = max(sum, numbers[idx] + numbers[size-idx-1]);
            idx++;
        }
        return sum;
    }
};
