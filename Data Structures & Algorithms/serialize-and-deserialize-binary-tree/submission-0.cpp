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

class Codec {
   public:
    void levelOrder(string& s, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr)
                s += "N,";
            else {
                s += to_string(node->val) + ',';
                q.push(node->left);
                q.push(node->right);
            }
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if (!root) return s;
        levelOrder(s, root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string token = "";

        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(ss, token, ',');
            if (token != "N") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }

            getline(ss, token, ',');
            if (token != "N") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }
        return root;
    }
};
