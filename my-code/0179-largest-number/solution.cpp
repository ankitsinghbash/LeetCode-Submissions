class Solution {
public:

static bool cmp(string &num1,string &num2){
    string first = num1+num2;
    string second = num2+num1;
    return first>second;
}


    string largestNumber(vector<int>& nums) {
        
        vector<string> store;
        for(int i=0;i<nums.size();i++){
            store.push_back(to_string(nums[i]));
        }
  
        sort(store.begin(),store.end(),cmp);
        if(store[0]=="0") return "0"; 
        string ans;
        for(int i=0;i<store.size();i++){
            ans+=store[i];
        }
        return ans;
    }
};
