class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> sa;
        unordered_set<int> sb;
        vector<int> C(A.size()+1,0);
        int j=1;
        for(int i=0;i<A.size();i++){
            int cnt = 0;
            if(A[i]==B[i]){
                sa.insert(A[i]);
                sb.insert(B[i]);
                C[j]=C[j-1]+1;
            }
            else{
                if(sb.find(A[i])!=sb.end()){
                    cnt++;
                }
                if(sa.find(B[i])!=sa.end()){
                    cnt++;
                }
                sa.insert(A[i]);
                sb.insert(B[i]);
                C[j]=C[j-1]+cnt;
            }
            j++;
        }
        C.erase(C.begin());
        return C;
    }
};
