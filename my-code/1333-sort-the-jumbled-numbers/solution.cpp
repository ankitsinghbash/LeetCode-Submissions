class Solution {
public:
   struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
             //if(a.first==b.first)  //no need to do anything 
             return a.first<b.first;   //so that value is in ascending order:
    }
   };


    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
          unordered_map<char,char> mp;
          for(int i=0;i<mapping.size();i++){
              char ch = i+'0';
              char ch1 = mapping[i]+'0';
              mp[ch] = ch1;    //index vs element:
          }
        



         vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
             string str = to_string(nums[i]);
             string mystr;
             for(int j=0;j<str.size();j++){
                   char ch = str[j];
                   mystr+=mp[ch];
             }


             int j=0;
             while(j<mystr.size() && mystr[j]=='0'){
                j++;
             }


             string newstr;
             while(j<mystr.size()){
                 newstr+=mystr[j];
                 j++;
             }



            int new_value = 0;
             if(newstr.size()!=0){
               new_value = stoi(newstr);
             }
             else{
                new_value = 0;
             }

             vec.push_back({new_value,nums[i]});


        }


        sort(vec.begin(),vec.end(),cmp());

        vector<int> ans;
        for(int i=0;i<vec.size();i++){
            ans.push_back(vec[i].second);
        }

        return ans;


    }
};


//991 -> 669:
//338 -> 000
//38  -> 07

//669
//7
//7

//7 , 8 , 669
//[38,338,991]:


