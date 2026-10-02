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
class BSTIterator {
    private:
        // Explicit stack to simulate and pause the recursion
        stack<TreeNode*> st;
        // Helper function to push the current node and all its left children
        void pushAllLeft(TreeNode* node) {
            while (node != nullptr) {
                st.push(node);
                node = node->left;
            }
        }
    public:
        BSTIterator(TreeNode* root) {
            pushAllLeft(root);
        }
        
        int next() {
            TreeNode* topNode = st.top();
            st.pop();
            
            if (topNode->right != nullptr) {
                pushAllLeft(topNode->right);
            }
            
            return topNode->val;
        }
        
        bool hasNext() {
            return !st.empty();
        }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */