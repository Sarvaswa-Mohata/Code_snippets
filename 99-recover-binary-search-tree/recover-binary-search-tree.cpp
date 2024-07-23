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
private:
    TreeNode* first;
    TreeNode* last;
    TreeNode* middle;
    TreeNode* prev;
public:
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        if(prev!=nullptr && (prev->val>root->val)){
            //first violation:
            if(!first){
                first = prev;
                middle=root;
            }
            else{
                last = root;
            }
        }
        prev=root;
        inorder(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        //initialization
        first = last = middle = NULL;
        prev = new TreeNode(INT_MIN);
        //inorder traversal :
        inorder(root);
        //returning ans:
        if(last)
        swap(first->val, last->val);
        else if(middle)
        swap(first->val, middle->val);
        return;
    }
};