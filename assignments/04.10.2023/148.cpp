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
    void mergeSort(vector<int>& nums, int start, int end){
        if(start>=end){
            return;
        }
        int mid = (start+end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, start, end, mid);
    }
    void merge(vector<int>& nums, int start, int end, int mid){
        vector<int> arr2;
        int a1 = start;
        int a2 = mid+1;
        while(a1<=mid && a2<=end){
            if(nums[a1]<nums[a2]){
                arr2.push_back(nums[a1]);
                a1++;
            }
            else{
                arr2.push_back(nums[a2]);
                a2++;
            }
        }
        while(a1<=mid){
            arr2.push_back(nums[a1]);
            a1++;
        }
        while(a2<=end){
            arr2.push_back(nums[a2]);
            a2++;
        }
        for(int i=0; i<arr2.size(); i++){
            nums[start+i] = arr2[i];
        }
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        vector<int> temp;
        ListNode* head1 = head;
        while(head1!=NULL){
            temp.push_back(head1->val);
            head1=head1->next;
        }
        mergeSort(temp, 0, temp.size()-1);
        ListNode* head2 = head;
        int i=0;
        while(head2!=NULL){
            head2->val = temp[i];
            head2=head2->next;
            i++;
        }
        return head;
    }
};