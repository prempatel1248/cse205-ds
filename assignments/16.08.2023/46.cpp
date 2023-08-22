class Solution {
public:
    void func(int i, vector<int>& nums, vector<vector<int>>& ans) {
        if (i == 1) {
            ans.push_back(nums);
            return;
        }

        for (int j = 0; j < i; j++) {
            swap(nums[j], nums[i - 1]);
            func(i - 1, nums, ans);
            swap(nums[j], nums[i - 1]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        func(nums.size(), nums, ans);
        return ans;
    }
};