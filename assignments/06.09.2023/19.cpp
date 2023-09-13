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
        ListNode* curr = head;
        int cnt = 1;
        while(curr!=NULL){
            curr = curr->next;
            cnt++;
        }
        cnt = cnt - n;
        if(cnt==1){
            curr = head;
            head = head -> next;
            curr -> next = NULL;
            delete curr;
        }
        else{
            curr = head;
            ListNode* prev = NULL;
            int i = 1;
            while(i<=cnt-1){
                prev = curr;
                curr = curr -> next;
                i++;
            }
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
        return head;
    }
};