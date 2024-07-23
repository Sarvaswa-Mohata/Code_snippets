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
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> v;
        if(start>end){
            v.push_back(nullptr);
            return v;
        }
        for(int i=start; i<=end;i++){
            for(auto it:helper(start, i-1)){
                for(auto jt:helper(i+1, end)){
                    TreeNode* node = new TreeNode(i);
                    node->right = jt;
                    node->left = it;
                    v.push_back(node);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return helper(1,n);
    }
};