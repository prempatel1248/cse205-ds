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
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast!=slow){
            slow = slow->next;
            if(fast->next==NULL){
                return false;
            }
            else{
                fast = fast->next->next;
            }
        }
        if(fast==NULL){
            return false;
        }
        else{
            return true;
        }
        
    }
};