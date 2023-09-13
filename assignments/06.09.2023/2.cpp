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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* head = l3;
        int carry = 0;
        while(l1 && l2){
            if((l1->val + l2->val + carry) >= 10){
                l3->next = new ListNode(((l1->val + l2->val + carry)%10));
                carry = 1;
                l1 = l1->next;
                l2 = l2->next;
                l3 = l3->next;
                if(!l1 || !l2){
                    l3->next = new ListNode(carry);
                }
            }
            else{
                l3->next = new ListNode((l1->val + l2->val)+carry);
                carry = 0;
                l1 = l1->next;
                l2 = l2->next;
                l3 = l3->next;
            }
        }
        if(l1==NULL){
            while(l2!=NULL){
                if(l2->val+carry >=10){
                    l3->next = new ListNode((l2->val + carry)%10);
                    carry = 1;
                    l2 = l2->next;
                    l3 = l3->next;
                    if(l2 == NULL){
                        l3->next = new ListNode(carry);
                    }
                }
                else{
                    l3->next = new ListNode((l2->val + carry)%10);
                    carry = 0;
                    l2 = l2->next;
                    l3 = l3->next;
                }
                
            }
        }
        if(l2==NULL){
            while(l1!=NULL){
                if(l1->val+carry >=10){
                    l3->next = new ListNode((l1->val + carry)%10);
                    carry = 1;
                    l1 = l1->next;
                    l3 = l3->next;
                    if(l1 == NULL){
                        l3->next = new ListNode(carry);
                    }
                }
                else{
                    l3->next = new ListNode((l1->val + carry)%10);
                    carry = 0;
                    l1 = l1->next;
                    l3 = l3->next;
                }
                
            }
        }


        return head->next;

    }
};