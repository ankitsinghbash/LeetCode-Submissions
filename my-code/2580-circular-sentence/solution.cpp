class Solution {
public:
   bool check(vector<string> &store){
          
        string prev = store[0];

        if(store.size()==1){
            int len = prev.size()-1;
            return prev[0]==prev[len];
        } 

        int len = prev.size();
        char start_ch = prev[0];
        char last_ch = prev[len-1];

        for(int i=1;i<store.size();i++){
            string curr = store[i];
            char curr_ch = curr[0];
            if(curr_ch!=last_ch){
                    return false;
            }
            int len1 = curr.size()-1;
            char curr_last = curr[len1];
            last_ch = curr_last;
        }

        return last_ch==start_ch;
    
   }


    bool solve(string sentence){
        vector<string> store;
        int n = sentence.size();
        string str;
        for(int i=0;i<n;i++){
             if(sentence[i]!=' '){
                 str+=sentence[i];
             }
             else{
                 string empty;
                 store.push_back(str);
                 str = empty;

             }
        }
        store.push_back(str);

        bool ans = check(store);
        return ans;
    }
    bool isCircularSentence(string sentence) {
        return solve(sentence);
    }
};
