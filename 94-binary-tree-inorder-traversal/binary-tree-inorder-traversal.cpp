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
        TreeNode* curr = root;
        stack<TreeNode*> st;
        vector<int> v;
        while(curr || !st.empty()){ //if curr becomes null or stack becomes empty break
            //first go as left as possible
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            //now curr is null
            curr = st.top();
            st.pop();
            v.push_back(curr->val);
            //now move to the right node 
            curr = curr->right;
        }
        return v;
    }
};