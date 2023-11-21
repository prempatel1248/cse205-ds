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
    void bst(TreeNode* &root, int &val){
        if(root->val > val){
            if(root->left){
                bst(root->left, val);
            }
            else{
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
                return;
            }
        }
        else if(root->val < val){
            if(root->right){
                bst(root->right, val);
            }
            else{
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        else{
            TreeNode* root1 = root;
            bst(root, val);
            return root1;
        }
        
    }
};