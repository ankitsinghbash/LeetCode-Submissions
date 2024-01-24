class Solution {
public:
    int cnt = 0;

    void solve(TreeNode* root, unordered_map<int, int>& mp) {
        if (root == nullptr) {
            return;
        }

        mp[root->val]++;

        if (root->left == nullptr && root->right == nullptr) {
            int odd_time = 0;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                if (it->second % 2 != 0) {
                    odd_time++;
                }
            }
            if (odd_time <= 1) { // Corrected condition: Check if there is at most 1 odd frequency
                cnt++;
            }
        }

        solve(root->left, mp);
        solve(root->right, mp);

        mp[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int, int> mp;
        solve(root, mp);
        return cnt;
    }
};

