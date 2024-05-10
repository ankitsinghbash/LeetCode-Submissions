class Solution {
public:
   typedef   pair<double,pair<int,int>> ll;
   struct Cmp{
        bool operator()(const ll &a, const ll &b) {
            return a.first < b.first;  
        }
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        //taken max heap:
    int n = arr.size();
    priority_queue<ll,vector<ll>> pq;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pair<int,int> P = {arr[i],arr[j]};
            double x =   double(arr[i])/double(arr[j]);
            pq.push({x,P});
            if(pq.size()>k)
            {
                pair<int,int> X = pq.top().second;
                 pq.pop();
            }
        }
    }

    
    ll X = pq.top();
    pair<int,int> L = X.second;
    vector<int> ans;
    ans.push_back(L.first);
    ans.push_back(L.second);
    return ans;
      
    }
};





