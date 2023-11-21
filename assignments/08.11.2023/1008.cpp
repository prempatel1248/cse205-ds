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
    void bst(vector<int>& left, vector<int>& right, TreeNode* &root){
        if(!left.empty()){
            TreeNode* temp = new TreeNode(left[0]);
            root->left = temp;
            vector<int> left2;
            vector<int> right2;
            for(int i=1; i<left.size(); i++){
                if(left[i]<left[0]){
                    left2.push_back(left[i]);
                }
                else{
                    right2.push_back(left[i]);
                }
            }
            bst(left2, right2, root->left);
        }
        if(!right.empty()){
            TreeNode* temp = new TreeNode(right[0]);
            root->right = temp;
            vector<int> left2;
            vector<int> right2;
            for(int i=1; i<right.size(); i++){
                if(right[i]<right[0]){
                    left2.push_back(right[i]);
                }
                else{
                    right2.push_back(right[i]);
                }
            }
            bst(left2, right2, root->right);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()){
            return NULL;
        }
        vector<int> left;
        vector<int> right;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++){
            if(preorder[i]<preorder[0]){
                left.push_back(preorder[i]);
            }
            else{
                right.push_back(preorder[i]);
            }
        }
        bst(left, right, root);
        return root;
    }
};