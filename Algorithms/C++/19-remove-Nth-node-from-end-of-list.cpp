/**
 * Be cautious for special cases, such as zero length linked list, deleting head node and so on.
 **/
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
        if(head == nullptr) return nullptr;
        int cnt = 1;  // count moving steps
        ListNode* p = head;
        ListNode* q = head;
        for(int i = 0; i < n-1; i++){
            q = q->next; 
            cnt++;
        }
        ListNode* pre;
        while(q->next != nullptr){
            pre = p;
            p = p->next;
            q = q->next;
            cnt++;
        }

        if(cnt == n){ // delete head node
            if(n == 1) return nullptr;
            else return head->next;
        }
        
        pre->next = p->next;
        return head;
    }
};