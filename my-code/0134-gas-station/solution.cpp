class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0;
        int total_cost=0;
        for(int i=0;i<gas.size();i++)
        {
            total_gas+=gas[i];
        }
        for(int i=0;i<cost.size();i++)
        {
            total_cost+=cost[i];
        }
        if(total_gas<total_cost){
            return -1;
        }

        int currcost=0;
        int i=0;
        int idx=0;
        while(i<gas.size()){
              if(currcost+gas[i]-cost[i]<0){
                  currcost=0;
                  idx=i+1;
                  i++;
              }
              else
              {
                  currcost+=gas[i]-cost[i];
                  i++;
              }
        }
        return idx;
    }
};
