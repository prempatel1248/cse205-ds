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
    ListNode * reverse(ListNode * ptr, int &k, int size)
    {
        if(size < k) return ptr;
        if(ptr == NULL) return ptr;

        ListNode * cur = ptr, *nxt = NULL, *pre = NULL;
        int cnt = 0;
        while(cur!=NULL && cnt < k)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            cnt++;
        }

        ptr->next = reverse(nxt,k,size-k);
        return pre;
    }

    int func(ListNode * ptr)    {
        int len = 0;
        while(ptr)
        {
            len++;
            ptr = ptr->next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = func(head);
        return reverse(head,k,n);
    }
};