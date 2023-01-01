class Solution {
public:
//using map:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, string> map1;
        std::unordered_map<string, char> map2;
        vector<string> words;

        int index = 0;
        string temp = "";
        while(index < s.size()){
            if(s[index] == ' ') {
                words.push_back(temp);
                temp = "";
            }
            else {
                temp += s[index];
            }
            index++;
        }
        words.push_back(temp);

        if(pattern.size() != words.size())
            return false;

        for(int i=0; i<pattern.size(); i++) {
            auto got1 = map1.find(pattern[i]);
            if(got1 == map1.end())
                map1[pattern[i]] = words[i];
            else if(got1->second != words[i])
                return false;

            auto got2 = map2.find(words[i]);
            if(got2 == map2.end())
                map2[words[i]] = pattern[i];
            else if(got2->second != pattern[i])
                return false;
        }

        return true;
    }
};

/*
   //using set to remove duplication:
    vector<string> vec;
    char separator = ' ';
    int i = 0;
    string s; 
    while (second[i] != '\0') {
        if (second[i] != separator) {
            s += second[i]; 
        } else {
            vec.push_back(s);
            s.clear();
        }
        i++;

    }
    vec.push_back(s);
   
   
    set<pair<char,string>> st;
    for(int i=0;i<pattern.size();i++){
        char ch = pattern.at(i);
        string word = vec[i];
        auto pairr  =make_pair(ch,word);
        st.insert(pairr);
    }
        
    vector<char> check_double;   //set check the duplication for both char and string simultaneously:
    vector<string> check_double1;
    set<pair<char,string>> :: iterator it;
    for(it=st.begin();it!=st.end();it++){
        check_double.push_back((*it).first);
        check_double1.push_back((*it).second);
    }
    //Now counter the duplication of set<pair> for each value:
    //if pair.first and pair.second any is greater then 1 mean return false:
    else
     return true:


*/
