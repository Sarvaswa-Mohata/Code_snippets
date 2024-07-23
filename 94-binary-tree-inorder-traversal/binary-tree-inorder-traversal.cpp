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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==nullptr) return v;
        if(root->left){
            v = inorderTraversal(root->left);
        }
        v.push_back(root->val);
        if(root->right){
            for(auto it:inorderTraversal(root->right)){
                v.push_back(it);
            }
        }
        return v;
    }
};