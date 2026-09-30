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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        if (n==1) return root;
        BSTConstruction(root, preorder, 1, n-1);
        return root;
    }
    void BSTConstruction(TreeNode* root, vector<int>& preorder, int start, int end){
        if (root == NULL || start>(preorder.size()-1) || end>(preorder.size()-1)) {
            return;
        }
        int i=start;
        while (i<=end) {
            if (preorder[i]<root->val) {
                i++;
            } else {
                break;
            }
        }
        if (preorder[start]<root->val) {
            root->left = new TreeNode(preorder[start]);
            BSTConstruction(root->left, preorder, start+1, i-1);
        } else {
            root->left = NULL;
        }
        if (i<=end && preorder[i]>root->val) {
            root->right = new TreeNode(preorder[i]);
            BSTConstruction(root->right, preorder, i+1, end);
        } else {
            root->right = NULL;
        }

    }
};