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
    int maxlen(TreeNode* root, int &ans){
        if(root==NULL){
            return 0;
        }
        int l = maxlen(root->left, ans);
        int r = maxlen(root->right, ans);
        if(l+r > ans){
            ans = l+r;
        }
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root==NULL){
            return 0;
        }
        maxlen(root, ans);
        return ans;
    }
};