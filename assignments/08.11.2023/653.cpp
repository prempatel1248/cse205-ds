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
    bool find(TreeNode* root, int k){
        if(root==NULL){
            return false;
        }
        if(root->val == k){
            return true;
        }
        else if(root->val > k){
            return find(root->left, k);
        }
        else{
            return find(root->right, k);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL && k!=0){
            return false;
        }
        int num1 = root->val;
        if(find(root->left, k-num1) || find(root->right, k-num1)){
            return true;
        }
        else{
            return findTarget(root->left, k) && findTarget(root->right, k);
        }
    }
};