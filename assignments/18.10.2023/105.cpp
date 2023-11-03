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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        TreeNode* temp = new TreeNode(preorder[0]);
        int i=0;
        vector<int> inleft;
        vector<int> inright;
        vector<int> preleft;
        vector<int> preright;
        while(inorder[i]!= temp->val){
            inleft.push_back(inorder[i]);
            i++;
        }
        for(int j=1; j<=i; j++){
            preleft.push_back(preorder[j]);
        }
        i++;
        for(int j=i; j<preorder.size(); j++){
            preright.push_back(preorder[j]);
        }
        while(i<preorder.size()){
            inright.push_back(inorder[i]);
            i++;
        }
        if(!inleft.empty()){
            temp->left = buildTree(preleft, inleft);
        }
        if(!inright.empty()){
            temp->right = buildTree(preright, inright);
        }
        return temp;
    }
};