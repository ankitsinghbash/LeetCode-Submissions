class Solution {
public:
    vector<int> ans;
    vector<int> lexicalOrder(int n) {
        vector<string> store;
        for(int i=1;i<=n;i++){
            string str = to_string(i);
            store.push_back(str);
        }
        sort(store.begin(),store.end());
        for(auto x : store){
            int val = stoi(x);
            ans.push_back(val);
        }
        return  ans;
    }
};
