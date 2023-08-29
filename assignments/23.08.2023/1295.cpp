class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int j=0;
        for(int i=0; i<=(nums.size()-1); i++){
            if(int(floor((log10(nums[i]))+1)) % 2 ==0){
                j=j+1;
            }
        }
        return j;
    }
};