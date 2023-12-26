struct pairhash{
    template <class T1,class T2>
    size_t operator()(const pair<T1,T2> &a)const{
        auto x1 = hash<T1>{}(a.first);
        auto x2 = hash<T2>{}(a.second);
        return x1^x2;
    }
};
class Solution {
public:

    bool isPathCrossing(string path) {

        unordered_set<pair<int,int>,pairhash> st;
        int x=0;
        int y=0;
        st.insert({0,0});
        for(int i=0;i<path.size();i++){
            if(path[i]=='E'){
                   x++;
            }
            else if(path[i]=='W'){
                x--;
            }
            else if(path[i]=='N'){
                y++;
            }
            else {
                y--;
            }

            if(st.find({x,y})!=st.end()){
                return true;
            }
            st.insert({x,y});
        }
        return false;
    }
};
