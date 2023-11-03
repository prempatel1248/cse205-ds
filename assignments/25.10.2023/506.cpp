class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        vector<string> ans(score.size());
        
        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }
        
        int j = 1;
        while (!pq.empty()) {
            auto top = pq.top();
            int scoreIndex = top.second;
            
            if (j == 1) {
                ans[scoreIndex] = "Gold Medal";
            } else if (j == 2) {
                ans[scoreIndex] = "Silver Medal";
            } else if (j == 3) {
                ans[scoreIndex] = "Bronze Medal";
            } else {
                ans[scoreIndex] = to_string(j);
            }
            
            pq.pop();
            j++;
        }
        
        return ans;
    }
};
