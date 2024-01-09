class Solution {
public:
    int solve(TreeNode *&root,unordered_map<int,int> &mp){
        if(root==NULL) return 0;
        int  sum=0;
        sum = root->val+solve(root->left,mp)+solve(root->right,mp);
        mp[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        solve(root,mp);
        vector<pair<int,int>> vec;  //cnt vs value:
        for(auto it = mp.begin();it!=mp.end();it++){
            vec.push_back({it->second,it->first});
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());  //cnt vs value:       
        vector<int> ans;
        int firstcnt = vec[0].first;
        ans.push_back(vec[0].second);
        for(int i=1;i<vec.size();i++){
            if(vec[i].first==firstcnt){
                ans.push_back(vec[i].second);
            }
            else{
                break;
            }
        }
        return ans;
    }
};

