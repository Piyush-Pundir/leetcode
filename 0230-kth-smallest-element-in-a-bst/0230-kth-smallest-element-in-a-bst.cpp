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
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans=-1;
        inorderTraversal(root, k, cnt, ans);
        return ans;
    }
    bool inorderTraversal(TreeNode* root, int &k, int &cnt, int &ans) {
        if (root==NULL) return false;
        if (inorderTraversal(root->left, k, cnt, ans))
            return true;
        cnt++;
        if (cnt==k) {
            ans = root->val;
        }
        if (inorderTraversal(root->right, k, cnt, ans))
            return true;
        return false;
    }
};