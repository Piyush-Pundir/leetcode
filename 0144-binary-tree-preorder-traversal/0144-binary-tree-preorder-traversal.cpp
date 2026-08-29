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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *cur = root;
        while (cur!=NULL) {
            if(cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = cur;
                    inorder.push_back(cur->val);// whenever you are marking the thread this is the moment you store it in the ans
                    cur = cur->left;
                }
                else {
                    prev->right = NULL; // removing the thread
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};