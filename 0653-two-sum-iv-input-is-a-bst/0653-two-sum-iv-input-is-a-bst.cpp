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
    stack<TreeNode*> st;
    bool reverse; 
    
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            if (reverse == true) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
 
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        
        if (reverse == true) {
            pushAll(topNode->left);
        } 
        else {
            pushAll(topNode->right);
        }
        
        return topNode->val;
    }
};


class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        
        // Initialize one iterator at the minimum and one at the maximum
        BSTIterator leftIter(root, false);
        BSTIterator rightIter(root, true);
        
        int i = leftIter.next();
        int j = rightIter.next();
        
        while (i < j) {
            int currentSum = i + j;
            
            if (currentSum == k) {
                return true;
            }
            
            if (currentSum < k) {
                i = leftIter.next();
            } 
            else {
                j = rightIter.next();
            }
        }
        
        return false;
    }
};
