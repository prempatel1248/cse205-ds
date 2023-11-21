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
    void recoverright(TreeNode* &root, TreeNode* &right){
        if(right){
            if(root->val > right->val){
                swap(root->val, right->val);
                recoverright(root, right);
            }
            recoverright(root, right->left);
            recoverright(root, right->right);
        }
    }
    void recoverleft(TreeNode* &root, TreeNode* &left){
        if(left){
            if(root->val < left->val){
                swap(root->val, left->val);
                recoverleft(root, left);
            }
            recoverleft(root, left->left);
            recoverleft(root, left->right);
        }
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL){
            return;
        }
        // TreeNode* left = root->left;
        // TreeNode* right = root->right;
        recoverleft(root, root->left);
        recoverright(root, root->right);
        recoverleft(root, root->left);
        recoverTree(root->left);
        recoverTree(root->right);
    }
};