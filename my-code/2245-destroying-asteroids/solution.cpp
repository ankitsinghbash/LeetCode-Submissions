class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        long long int mass1=mass;
        for(int i=0;i<ast.size();++i){
            if(mass1<ast[i]){
                return false;
            }
             mass1+=ast[i];
        }
        return true;
    }
};
