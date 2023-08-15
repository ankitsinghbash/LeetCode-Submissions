class Solution {
public:
   typedef pair<double, pair<int, int>> P; 
   struct Cmp{
        bool operator()(const P &a, const P &b) {
            return a.first > b.first;
        }
    };
    priority_queue<P,vector<P>,Cmp> store;

    void solve(int idx, vector<int> &arr) {
        if (idx >= arr.size()) return;

        for (int i = 0; i < arr.size(); i++) {
            if (idx != i) { // Avoid dividing by itself
                double value = (double)arr[idx] / (double)arr[i];
                store.push({value, {arr[idx], arr[i]}});
            }
        }
        solve(idx + 1, arr);
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        solve(0, arr);

        while (k > 1) { // Loop until k becomes 1
            store.pop();
            k--;
        }

        pair<double, pair<int, int>> P = store.top();
        vector<int> ans;
        ans.push_back(P.second.first);
        ans.push_back(P.second.second);
        return ans;
    }
};

