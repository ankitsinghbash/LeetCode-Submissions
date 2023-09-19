class Solution {
public:
    typedef pair<int,int> P;
    //Inbuilt default for max-head:
    struct cmp{
        bool operator()(const pair<int,int> &a,const pair<int,int> &b){
                 if(a.first==b.first){
                    return a.second<b.second;
                 }
                 return a.first<b.first; //defalut for max-head:
        }
    };


    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //Now use logic for duplicate right - most inserting in binary tree:
        //donot change right most inserting on the basis of desending order sorted:
        //just change the condition in the right most inserting part:
        priority_queue<P,vector<P>,cmp> pq;  //make it max-heap:
        vector<pair<int,int>> ans;
        for(int i=0;i<mat.size();i++){
             int left = mat[i][0];
             int right = mat[i].size();
             int target = 1;
             //using binary serach standard template:
             while(left<right){
                 int mid = left+(right-left)/2;
                 if(mat[i][mid]<target){
                       right = mid;
                 }
                 else{
                     left = mid+1;
                 }
             }

             pq.push({left+1,i});
             if(pq.size()>k){
                 pq.pop();
             }
        }
        vector<int> store(k,0);
        for(int i=store.size()-1;i>=0;i--){
            store[i]=pq.top().second;
            pq.pop();
        }

        return store;
    }
};

//brute force:
// class Solution {
// public:

//   struct cmp{
//       bool operator()(const pair<int,int> &a,const pair<int,int> &b){
//              if(a.first==b.first){
//                  return a.second<b.second;
//              }
//              return a.first<b.first;
//       }
//   };


//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         //brute force :
//         //binary search :
//         vector<pair<int,int>> store;
//         for(int i=0;i<mat.size();i++){
//             int counter1=0;
//             for(int j=0;j<mat[0].size();j++){
//                   if(mat[i][j]==1){
//                       counter1++;
//                   }
//             }
//             store.push_back({counter1,i});
//         }

//         sort(store.begin(),store.end(),cmp());
//         vector<int> ans;
//         for(int i=0;i<k;i++){
//             int idx = store[i].second;
//             ans.push_back(idx);
//         }
//         return ans;



//     }
// };
