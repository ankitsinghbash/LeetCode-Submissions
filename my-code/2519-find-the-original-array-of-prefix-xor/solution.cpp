class Solution {
public:
    
    int solve(int a,int b){
       
        vector<int> store(32);
        string first = bitset<32>(a).to_string();
        string second  = bitset<32>(b).to_string();
      


        for(int j=31;j>=0;j--){
            if(first[j]=='1' && second[j]=='0'){
                store[j]=1;
            }
            else if(first[j]=='0' && second[j]=='1'){
                store[j]=1;
            }
            else{
                store[j]=0;
            }
        }

       
        int pow_2 = 0;
        int total=0;
        for(int j=31;j>=0;j--){
            int val = store[j]*pow(2,pow_2);
            total+=val;
            pow_2++;
        }

    
        return total;

    }


    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> store(n);
        vector<int> prev_xor(n);

        store[0]=pref[0];
        prev_xor[0]=pref[0];
        for(int i=1;i<n;i++){
            int x = solve(pref[i],prev_xor[i-1]);
            prev_xor[i]=prev_xor[i-1]^x;
            store[i]=x;
        }

        return store;
    }
};
