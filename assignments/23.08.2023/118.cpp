class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> temp;
        vector<int>set;
        vector<vector<int>> ans;
        temp.push_back(1);
        ans.push_back(temp);
        set = temp;
        temp.clear();
        for(int i=1; i<numRows; i++){
            temp.push_back(1);
            for(int j=0; j<set.size()-1; j++){
                temp.push_back(set[j]+set[j+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            set = temp;
            temp.clear();
        }
        return ans;
    }
};