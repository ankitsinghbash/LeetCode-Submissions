class Solution {
public:
  bool check_anagram(string str1,string str2){
      if(str1.size()!=str2.size()) return false;
      vector<int> window_str1(26,0);
      vector<int> window_str2(26,0);
      for(int i=0;i<str1.size();i++){
          window_str1[str1[i]-'a']++;
          window_str2[str2[i]-'a']++;
      }
      if(window_str1==window_str2){
          return true;
      }
      return false;
  }
  


    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string start = words[0];
        ans.push_back(start);
        for(int i=1;i<words.size();i++){
            string next = words[i];
            if(check_anagram(start,next)){
                continue;
            }
            else{
                ans.push_back(words[i]);
                start = words[i];
            }
        }
        return ans;
    }
};
