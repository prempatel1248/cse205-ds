class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> temp;
        vector<int> ans;
        int j=1;
        while(temp.size()!=nums.size()){
            temp.push_back(j);
            j++;
        }
        for(int i:temp){
            mp[i]=mp[i]+1;
        }
        for(int i:nums){
            mp[i]=mp[i]+1;
        }
        for(auto i:mp){
            if(i.second == 3){
                ans.push_back(i.first);
                break;
            }
        }
        for(auto i:mp){
            if(i.second == 1){
                ans.push_back(i.first);
                break;
            }
        }
        return ans;
    }
};