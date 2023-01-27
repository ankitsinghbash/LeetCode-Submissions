/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> big;
    vector<vector<int>> levelOrder(Node* root) {

       if(root==NULL){
           return {};
       }

        //bfs;
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int N = qu.size();
            vector<int> sm;
            while(N--){
                Node *node = qu.front();
                sm.push_back(node->val);
                qu.pop();

                for(Node *child : node->children){
                    qu.push(child);
                }
            }
            big.push_back(sm);
            sm.clear();
        }
        return big;
    }
};
