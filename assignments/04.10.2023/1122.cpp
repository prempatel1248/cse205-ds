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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        for(int i=0; i<arr2.size(); i++){
            for(int j=0; j<arr1.size(); j++){
                if(arr1[j]==arr2[i]){
                   ans.push_back(arr1[j]);
                }
            }
        }
        int temp1;
        vector<int> temp;
        for(int i=0; i<arr1.size(); i++){
            int j=0;
            while(j<ans.size()){
                if(arr1[i]==ans[j]){
                    break;
                }
                j++;
            }
            if(j==ans.size()){
                temp.push_back(arr1[i]);
            }
        } 
        mergeSort(temp, 0, temp.size()-1);
        for(int i=0; i<temp.size(); i++){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};