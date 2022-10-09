class Solution {
public:
     vector <string> v; // global vector
    void compute (int i,string s, vector <string> wd,string path){
         
           if (i>= s.length()){ // base case
               
               path.pop_back(); // backtracking 
               v.push_back(path);
           }
            string temp;
           for (int j=i; j< s.length(); j++){
                 temp+= s[j]; // check every character 
               if (find(wd.begin(), wd.end(), temp)!= wd.end()){ // using find fn. to check word present or not in dict
                   
                  compute(j+1,s, wd,path+temp+' '); //important to add ' ' because in pop condition we pop last element:
                  
              }
           }
      }
    vector<string> wordBreak(string s, vector<string>& w){
       string path;
       int i=0;
       compute (i,s,w,path);
          return v;
    }
};
