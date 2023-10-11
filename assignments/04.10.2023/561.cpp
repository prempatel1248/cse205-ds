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
    int arrayPairSum(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        int ans=0;
        for(int i=0; i<nums.size()-1; i=i+2){
            ans = ans + min(nums[i], nums[i+1]);
        }
        return ans;
    }
};