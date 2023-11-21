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
    int freq(TreeNode* &root){
        if(root==NULL){
            return 0;
        }
        int l = freq(root->left);
        int r = freq(root->right);
        return l+r+1;

    }
    int kthSmallest(TreeNode* root, int k) {
        int l = freq(root->left);
        if(l >= k){
            return kthSmallest(root->left, k);
        }
        if(l+1 == k){
            return root->val;
        }
        else{
            return kthSmallest(root->right, k-l-1);
        }
    }
};