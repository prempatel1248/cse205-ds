class Solution {
public:
    void comb(int i, int k, int n, vector<int>& sub, vector<vector<int>>& ans){
        if(sub.size()==k){
            ans.push_back(sub);
        }
        else{
            for(int j=i; j<=n; j++){
                sub.push_back(j);
                comb(j+1, k, n, sub, ans);
                sub.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sub;
        comb(1, k, n, sub, ans);
        return ans;
    }
};