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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* headAA = headA;
        ListNode* headBB = headB;
        int cntA = 0;
        int cntB = 0;
        while(headAA!=NULL){
            headAA = headAA->next;
            cntA++;
        }
        while(headBB!=NULL){
            headBB = headBB->next;
            cntB++;
        }
        headAA = headA;
        headBB = headB;
        if(cntA < cntB){
            int i=0;
            while(i<(cntB-cntA)){
                headBB = headBB->next;
                i++;
            }
            while(headAA!=NULL){
                if(headBB == headAA){
                return headAA;
                }
                headAA = headAA->next;
                headBB = headBB->next;
            }
        }
        else{
            int i=0;
            while(i<(cntA-cntB)){
                headAA = headAA->next;
                i++;
            }
            while(headAA!=NULL){
                if(headBB == headAA){
                return headAA;
                }
                headAA = headAA->next;
                headBB = headBB->next;
            }
        }
        return NULL;
    }
};