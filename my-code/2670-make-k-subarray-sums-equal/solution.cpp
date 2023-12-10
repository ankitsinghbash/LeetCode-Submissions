class Solution {
public:
   long long find_val(vector<long long> &arr,int x){
       long long total=0;
       for(int i=0;i<arr.size();i++){
           total+=abs(arr[i]-x);
       }
       return total;
   }

    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long n = arr.size();
        long long answer=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }
            int idx = i;
            vector<long long> temp;

            while(visited[idx]==false){
                visited[idx]=true;
                int val = arr[idx];
                temp.push_back(val);
                idx = (idx+k)%n;
            }

            //make all element same with minimum count use logic on temp vector:
            //example 1 ko 1 ke lyia 0 chayia:
            //example 1,2,3 me sabko 2,2,2 ke lyia 2 chayia:
             long long curr=0;
             sort(temp.begin(),temp.end());
             int len = temp.size();
             if(len%2==0){
               int mid = len/2;
               int second_mid = len/2-1;
               long long first = find_val(temp,temp[mid]);
               long long second = find_val(temp,temp[second_mid]);
               curr=min(first,second);
             }
            else{
              int mid = len/2;
              curr+=find_val(temp,temp[mid]);
            }
           
            answer+=curr;
        }
        return (answer);
    }
};
