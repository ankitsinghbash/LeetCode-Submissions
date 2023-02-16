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
    int maxDepth(Node* root) {
      
      if(root==NULL) return 0;


       queue<Node*> qu;
       qu.push(root);
       int level=0;
       while(!qu.empty()){
           int size = qu.size();
           while(size--){
               Node *node = qu.front();
               qu.pop();
               for(int i=node->children.size()-1;i>=0;i--){
                   qu.push(node->children[i]);
               }
           }
           level++;
       }
       return level;
    }
};
