class WordDictionary {
public:

   struct TrieNode{
       bool isEndofword;
       TrieNode *children[26];
   };

   TrieNode *getnode(){
       TrieNode *new_node = new TrieNode();
       new_node->isEndofword = false;
       for(int i=0;i<26;i++){
           new_node->children[i]=NULL;
       }
       return new_node;
   }
    
    TrieNode *root;
    WordDictionary() {
        root = getnode();
    }
    
    void addWord(string word) {
        TrieNode *crowl = root;
        for(int i=0;i<word.size();i++){
            int idx =  word[i]-'a';
            if(crowl->children[idx]==NULL){
                crowl->children[idx]=getnode();
            }
           crowl =  crowl->children[idx];
        }
        crowl->isEndofword = true;
    }

 
    bool search_word(TrieNode *root,string word){
      
      TrieNode *crowl = root;
      for(int i=0;i<word.size();++i){
          int idx = word[i]-'a';
          char ch = word[i];
          if(ch=='.'){
              for(int j=0;j<26;j++){
                  if(crowl->children[j]!=NULL){
                      if(search_word(crowl->children[j],word.substr(i+1))){
                          return true;
                      }
                  }
              }
              return false;
          }
          else if(crowl->children[idx]==NULL){
              return false;
          }
          crowl=crowl->children[idx];
      }
      if(crowl!=NULL && crowl->isEndofword==true){
          return true;
      }
      return false;
   }

    
    bool search(string word){
        return search_word(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
