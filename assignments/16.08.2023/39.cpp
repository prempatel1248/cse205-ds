class Solution {
public:
    void combsum(int i, int target, vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans){
        if(i>=candidates.size()){
            if(target<=0){
                ans.push_back(curr);
            }
            return;
        }
        if(candidates[i]<=target){
            curr.push_back(candidates[i]);
            combsum(i, target-candidates[i], candidates, curr, ans);
            curr.pop_back();
        }
        combsum(i+1, target, candidates, curr, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        combsum(0, target, candidates, curr, ans);
        return ans;
    }
};