/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool common(TreeNode* &root, TreeNode* &p, TreeNode* &q){
        if(root==NULL){
            return false;
        }
        if(root == p || root == q){
            return true;
        }
        else{
            return common(root->left, p ,q) || common(root->right, p, q);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
        else if(root==p || root==q){
            return root;
        }
        else if(root->left && root->right){
            if(common(root->left, p, q) && common(root->right, p, q)){
                return root;
            }
            else if(common(root->left, p, q)){
                return lowestCommonAncestor(root->left, p, q);
            }
            else{
                return lowestCommonAncestor(root->right, p, q);
            }
        }
        else if(root->left){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(root->right){
            return lowestCommonAncestor(root->right, p, q);
        }
        else{
            return root;
        }
    }
};