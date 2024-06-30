class DSU{
       vector<int> parent;
       vector<int> rank;
       int component;
    
        public:
        DSU(int  n){
           component = n;
           parent.resize(n+1);
           rank.resize(n+1);
           for(int i=1;i<=n;i++){
             parent[i] = i;
          }
       }


       int find(int x){
            if(parent[x]==x){
                return x;
            }

            return parent[x] = find(parent[x]);
       }
    

    
       void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        
        if (x_parent == y_parent) 
            return;
        
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
        }
        component--;
    }
  
      bool iscomponent(){
        return component==1;
    }
    

};


struct cmp{
    bool operator()(vector<int> &a ,vector<int> &b){
        return a[0]>b[0];
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
         int total_edge= 0;

         DSU Alice(n);
         DSU Bob(n);

         sort(edges.begin(),edges.end(),cmp());  ///sort in that way so we get type 3 first: and apply dfs on type 3:
         for(int i=0;i<edges.size();i++){
             int type = edges[i][0];
             int  u = edges[i][1];
             int v = edges[i][2];

              
             if(type == 3){
                 bool isadded = false;
                 if(Alice.find(v)!=Alice.find(u)){
                      Alice.Union(u,v);
                      isadded = true;
                 }

                 if(Bob.find(v)!=Bob.find(u)){
                    Bob.Union(u,v);
                    isadded=true;
                 }

                 if(isadded==true){
                     total_edge++;
                 }
             } 

             if(type == 1){  //alice:
                  bool isadded = false;
                  if(Alice.find(u)!=Alice.find(v)){
                       Alice.Union(u,v);
                       isadded = true;
                  }
                  if(isadded==true){
                      total_edge++;
                  }
             }

             if(type==2){
                 bool isadded = false;
                 if(Bob.find(u)!=Bob.find(v)){
                    Bob.Union(u,v);
                    isadded = true;
                 }
                 if(isadded == true){
                     total_edge++;
                 }
             }
         }


         if(Alice.iscomponent()==true && Bob.iscomponent()==true){
              return edges.size()-total_edge;
         }
         return -1;
         
    }
};
