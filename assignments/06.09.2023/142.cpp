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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head==NULL){
            return NULL;
        }
        if(head->next == NULL){
            return NULL;
        }
        slow = slow->next;
        fast = fast->next->next;
        while(fast!=NULL && fast!=slow){
            if(fast->next == NULL){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast==NULL){
            return NULL;
        }
        else{
            fast = head;
            while(fast != slow){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
};