class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>ans;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>matrixRow;
        for(int c=0; c<col; c++){
            for(int r=0; r<row; r++){
                matrixRow.push_back(matrix[r][c]);
            }
            ans.push_back(matrixRow);
            matrixRow.clear();
        }
        return ans;
    }
};