class Solution {
public:
    int minimumOperations(string str) {
      int phone = INT_MAX;
      int phone_size = str.size();

     if (phone_size==1) {
        return 1;
     } else if (phone_size == 2) {
     if(str=="25" || str=="50" || str=="75" || str=="00") {
         return 0;
     } else if (str[0]=='0' || str[1]=='0') {
         return 1;
     } else {
         return 2;
     }
      }

     int phone_count = count(str.begin(),str.end(),'0');

     for (int i=0; i<phone_size;i++) {
       for (int j=i+1;j<phone_size;j++) {
          int phone_num = (str[i]-'0')*10 +(str[j]-'0');
          if (phone_num % 25 == 0) {
             int phone_a=j-i-1;
             int phone_b=phone_size -(j+1);
             phone = min(phone,phone_a+phone_b);
         }
     }
    }

    return phone==INT_MAX?phone_size-phone_count:phone;

    }
};
