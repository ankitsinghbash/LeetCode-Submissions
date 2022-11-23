class Solution {
public:
    int findContentChildren(vector<int>& boxes, vector<int>& chosize) {
        int counter=0;
        for(int i=0;i<chosize.size();i++)
        {
            int val = chosize[i];
            for(int j=0;j<boxes.size();j++)
            {
                 if(val==boxes[j])
                 {
                     counter++;
                     boxes.erase(boxes.begin()+j);
                     chosize.erase(chosize.begin()+i);
                     break;
                 }
            }
        }
        sort(boxes.begin(),boxes.end());
        sort(chosize.begin(),chosize.end());

        for(int i=0;i<chosize.size();i++)
        {
            int valu = chosize[i];
            for(int j=0;j<boxes.size();j++)
            {
                if(valu>=boxes[j])
                {
                    counter++;
                    boxes.erase(boxes.begin()+j);
                    break;
                }
            }
        }

        return counter;
    }
};
