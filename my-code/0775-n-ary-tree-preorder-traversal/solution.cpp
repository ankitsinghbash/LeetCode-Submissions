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
    vector<int> preorder(Node* root) {
        if(root==NULL) return {};

        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node *node = st.top();
            st.pop();
            ans.push_back(node->val);
            //put the element in reverse order:
            for(int i=node->children.size()-1;i>=0;i--){  //push element from right ---> left:
                st.push(node->children[i]);
            }
        }
        return ans;
    }
};
