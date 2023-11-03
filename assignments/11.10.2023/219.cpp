class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]==0){
                mp[nums[i]]=i+1;
            }
            else{
                int val = mp[nums[i]];
                int diff = i+1-val;
                if(diff<=k){
                    return true;
                }
                else{
                    mp[nums[i]]=i+1;
                }
            }
        }
        return false;
    }
};