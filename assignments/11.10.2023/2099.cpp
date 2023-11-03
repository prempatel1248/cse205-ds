class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> temp;
        vector<int> arr;
        map<int,int>mp;
        for(int x:nums)arr.push_back(x);
        sort(arr.rbegin(), arr.rend());
        cout<<"arr = ";
        for(int x:arr)cout<<x<<" ";
        cout<<endl;
        for(int i=0; i<k; i++){
            temp.push_back(arr[i]);
        }
        for(int i:temp){
            mp[i]++;
        }
        cout<<"temp = ";
        for(int x:temp)cout<<x<<" ";
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]!=0){
                ans.push_back(nums[i]);
                mp[nums[i]]--;
            }
        }
        return ans;
    }
};