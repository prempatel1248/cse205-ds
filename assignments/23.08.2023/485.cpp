class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int ones=0;
        for(int i=0; i<=nums.size()-1; i++){
            if(nums[i]==1){
                ones=ones+1;
                if(ones>max){
                    max=ones;
                }
            }
            else{
                ones=0;
            }
        }
        return max;
    }
};