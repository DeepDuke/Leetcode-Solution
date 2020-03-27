/*
Use current linked-list head of l1 to store the result linked-list's head node
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* iter = l1;
        ListNode* head = l1;
        int carry = 0;
        while(l1 || l2){
            int x = 0, y = 0;
            if(l1){
                x = l1->val;
                l1 = l1->next;
            }
            if(l2){
                y = l2->val;
                l2 = l2->next;
            }
            iter->val = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            if(iter->next == nullptr){
                iter->next = l2;
            }
            if(iter->next != nullptr){
                iter = iter->next;
            }
        }
        if(carry) iter->next = new ListNode(carry);
        return head;
    }
};