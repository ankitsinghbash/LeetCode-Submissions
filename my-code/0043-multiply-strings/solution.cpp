class Solution {
public:
    string multiply(string nums1, string nums2) {
         //normal multiple technique:
         int len1 = nums1.size()-1;
         int len2 = nums2.size()-1;

         vector<int> result(nums1.size()+nums2.size(),0);
         for(int i=len1;i>=0;i--){
             for(int j=len2;j>=0;j--){
                     int post2 = i+j+1;
                     int post1 = i+j;

                     int val1 = nums1[i]-'0';
                     int val2 = nums2[j]-'0';

                     int product = val1*val2;

                     product+=result[post2];
                     result[post1] += product/10;  //carry kar do:
                     result[post2] = product%10; 
             }
         }
      
       int i=0;
       while(i<result.size() && result[i]==0){
           i++;
       }
      
       if(i==result.size()){
           return "0";
       }

       string ans="";
       while(i<result.size()){
           ans+=to_string(result[i]);
           i++;
       }
       return ans;

    }
};
