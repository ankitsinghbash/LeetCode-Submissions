class Solution {
public:
    int maxx=0;
    void solve(int i,vector<string> &words,vector<char> &letters,vector<int> &score,vector<int> &freq,int curr){
           maxx = max(maxx,curr);
           if(i>=words.size()){
            return;
           }
    

          int j=0;
          int currentscore=0;
          vector<int> new_freq = freq;
          while(j<words[i].size()){
              char ch = words[i][j];
  
              if(freq[ch-'a']==0){
                break;
              }
            
              currentscore+=score[ch-'a'];
              freq[ch-'a']--;
              j++;

          }


          if(j==words[i].size()){
               solve(i+1,words,letters,score,freq,curr+currentscore);
          }
          //not taken:
           solve(i+1,words,letters,score,new_freq,curr);


    } 

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> visited(26,0);
        for(int i=0;i<letters.size();i++){
            int idx = letters[i]-'a';
            visited[idx]++;
        }
        int curr=0;
       
        solve(0,words,letters,score,visited,curr);
        return maxx;
    }
};
