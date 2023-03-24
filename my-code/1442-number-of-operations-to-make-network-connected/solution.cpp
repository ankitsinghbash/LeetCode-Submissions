class Solution {
public:
    //use karo rank compression dsu also:
    vector<int> parent;
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return find(parent[x]);
    }


    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent!=y_parent){
            parent[x_parent]=y_parent;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }

        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;    //initilize jab abne parent khud hai:
        }

        int components = n; //Total ilaka
        for(auto &vec : connections){
            if(find(vec[0])!=find(vec[1])){
                Union(vec[0],vec[1]);
                components--;
            }
        }
        return components-1;

    }
};
