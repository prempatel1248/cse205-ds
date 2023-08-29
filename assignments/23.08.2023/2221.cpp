class Solution {
public:
    void trisum(vector<int>& nums, int& sum){
        if(nums.size()==1){
            sum = nums[0];
            return;
        }
        vector<int> newNums;
        for(int i=0; i<nums.size()-1; i++){
            newNums.push_back((nums[i]+nums[i+1])%10);
        }
        trisum(newNums, sum);
        
    }
    int triangularSum(vector<int>& nums) {
        int sum=0;
        trisum(nums, sum);
        return sum;
    }
};