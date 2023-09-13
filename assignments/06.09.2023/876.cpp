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
    ListNode* middleNode(ListNode* head) {
        ListNode* head1 = head;
        int cnt = 0;
        while(head!=NULL){
            head = head -> next;
            cnt++;
        }
        head = head1;
        if(cnt%2==0){
            cnt = (cnt/2)+1;
        }
        else{
            cnt = (cnt+1)/2;
        }
        int i=1;
        while(i<cnt){
            head1 = head1 -> next;
            i++;
        }
        return head1;
    }
};