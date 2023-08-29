class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int j=0;
        for(int i=1; i<=(arr.size()+k); i++){
            if(j<arr.size() && i==arr[j]){
                j=j+1;
            }
            else{
                missing.push_back(i);
            }
        }
        return missing[k-1];
    }
};