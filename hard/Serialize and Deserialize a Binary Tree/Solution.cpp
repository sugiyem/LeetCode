/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "n";
        return to_string(root -> val) + "," + serialize(root -> left) 
            + "," + serialize(root -> right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string curr;
        queue<string> q;
        
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == ',') {
                q.push(curr);
                curr = "";
                continue;
            }
            
            curr += data[i];
        }
        
        if (curr.length()) q.push(curr);
        return buildFromQueue(q);
    }
    
    TreeNode* buildFromQueue(queue<string>& q) {
        string curr = q.front();
        q.pop();
        
        if (curr == "n") return nullptr;
        
        TreeNode* ans = new TreeNode(stoi(curr));
        ans -> left = buildFromQueue(q);
        ans -> right = buildFromQueue(q);
        
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));