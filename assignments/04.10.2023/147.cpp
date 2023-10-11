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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* head1 = head;
        ListNode* ans = new ListNode(head1->val);
        ans->next = NULL;
        ListNode* ans1 = ans;
        head1 = head1->next;
        while(head1!=NULL){
            ListNode* curr = ans1;
            ListNode* nxt = curr->next;
            ListNode* temp = new ListNode(head1->val);
            if(temp->val < ans1->val){
                temp->next = ans1;
                ans1 = temp;
            }
            else{
                while(nxt!=NULL){
                    if(temp->val < nxt->val){
                        temp->next = nxt;
                        curr->next = temp;
                        break;
                    }
                    nxt=nxt->next;
                    curr=curr->next;
                }
                if(nxt==NULL){
                    curr->next = temp;
                }
                
            }
            head1 = head1->next;
        }
        return ans1;  
    }
};