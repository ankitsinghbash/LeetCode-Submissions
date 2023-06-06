class Solution {
public:
  
   void filling(string str,unordered_map<string,int> &mp){
    
     string number = "";
    string first = "";
    string mainstr;
    for(int i=0;i<str.size();i++){
      char ch = str.at(i);
      number+=ch;
      if(ch==' '){
        first = number;
        mainstr = str.substr(i+1);
      }
    }
   
    int value = stoi(first);
    string newstr = mainstr;
    reverse(newstr.begin(),newstr.end());
    
    string x="";
    vector<string> store;
    for(int i=0;i<newstr.size();i++){
      char ch = newstr.at(i);
      if(ch=='.'){
         string check = x;
         reverse(check.begin(),check.end());
         store.push_back(check);
      }
     x+=ch;
    }
    string check1 = x;
    reverse(check1.begin(),check1.end());
    store.push_back(check1);
 
    
    for(int i=0;i<store.size();i++){
       string s = store[i];
       auto it = mp.find(s);
         mp[s]+=value;
    }
}


    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> mp;
        for(int i=0;i<cpdomains.size();i++){
            string str = cpdomains[i];
            filling(str,mp);
        }

      vector<string> answer;
     for(auto it = mp.begin();it!=mp.end();it++){
       string LL = to_string(it->second);
       LL+=" ";
       LL+=it->first;
       answer.push_back(LL);
     }
     return answer;
    }
};
