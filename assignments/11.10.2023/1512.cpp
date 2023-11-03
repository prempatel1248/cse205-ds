class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i:nums){
            if(mp.count(i)){
                ans = ans + mp[i];
            }
            mp[i] = mp[i]+1;
        }
        return ans;
    }
};