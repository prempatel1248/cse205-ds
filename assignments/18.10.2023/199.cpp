/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void side(TreeNode* root, vector<vector<int>> &ans){
        vector<int> temp1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(temp1);
                temp1.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                temp1.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> answer;
        if(root==NULL){
            return answer;
        }
        side(root, ans);
        for(int i=0; i<ans.size(); i++){
            answer.push_back(ans[i][ans[i].size()-1]);
        }
        return answer;
    }
};