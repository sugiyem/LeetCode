/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        
        if (clone.count(node)) {
            return clone[node];
        }
        
        clone[node] = new Node(node -> val);
        for (Node* neighbor : node -> neighbors) {
            clone[node] -> neighbors.push_back(cloneGraph(neighbor));
        }
        
        return clone[node];
    }
private:
    unordered_map<Node*, Node*> clone;
};