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
        ListNode* last = head;
        ListNode* mid = head;
        int cnt = 1;
        while(last->next != NULL){
            mid = mid->next;
            if(last->next->next==NULL){
                last = last->next;
                cnt = cnt + 1;
            }
            else{
                last = last->next->next;
                cnt = cnt + 2;
            }
        }
        if(cnt==2){
            if(head->val == last->val){
                return true;
            }
            else{
                return false;
            }
        }
        ListNode* nxt = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=mid){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        if(cnt%2 == 0){
            while(prev!=NULL){
                if(prev->val != mid->val){
                    return false;
                }
                prev = prev->next;
                mid = mid->next;
            }
        }
        else{
            mid = mid->next;
            while(prev!=NULL){
                if(prev->val != mid->val){
                    return false;
                }
                prev = prev->next;
                mid = mid->next;
            }
        }
        return true;
        
    }
};