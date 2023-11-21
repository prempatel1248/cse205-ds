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
    bool bstright(TreeNode* &root, int &value){
        if(root==NULL){
            return true;
        }
        if(root->val > value){
            return bstright(root->left, value) && bstright(root->right, value);
        }
        else{
            return false;
        }
    }
    bool bstleft(TreeNode* &root, int &value){
        if(root==NULL){
            return true;
        }
        if(root->val < value){
            return bstleft(root->left, value) && bstleft(root->right, value);
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(bstleft(root->left, root->val) && bstright(root->right, root->val)){
            return isValidBST(root->left) && isValidBST(root->right);
        }
        return false;
        
    }
};