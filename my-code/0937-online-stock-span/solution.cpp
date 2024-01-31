class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx=-1;
    StockSpanner() {
        
    }
    
    int next(int price) {
          idx++;
          if(idx==0){
              st.push({price,idx});
              return 1;
          }

          while(!st.empty() && st.top().first<=price){
              st.pop();
          }
          if(st.size()==0){
              st.push({price,idx});
              return idx+1;
          }
          int val = idx - st.top().second;
          st.push({price,idx});
          return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
