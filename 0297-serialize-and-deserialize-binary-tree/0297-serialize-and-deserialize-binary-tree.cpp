/**

Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (!root) {
            return "";
        }

        string s = "";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* curNode = q.front();
            q.pop();

            if (curNode == nullptr) {
                s += "#,";
            } 
            else {
                s += to_string(curNode->val) + ",";

                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data.empty()) {
            return nullptr;
        }

        // stringstream lets us read this string piece by piece, like an input stream.
        stringstream s(data);
        string str; // This is simply a variable that temporarily stores each value we read.

        getline(s, str, ','); //Read from s until you find , and store what you read in str.
        //So getline() is basically extracting one value at a time.

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // Read the left child value
            getline(s, str, ',');

            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                // stoi() : String To Integer
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read the right child value
            getline(s, str, ',');

            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        // Return the root of the reconstructed tree
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));