class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for(int i=0;i<candyType.size();i++){
            st.insert(candyType[i]);
        }
        int required = candyType.size()/2;
        int val = st.size()-required;
        if(val>0){
             return required;
        }
        return st.size();
        
    }
};
// required = 2:
//1--2
//2--1
//3--1
