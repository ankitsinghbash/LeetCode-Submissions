class Solution {

public:

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> v;

        int j= 0;

        while (j<nums1.size()){

            int x = nums1[j];

            for(int i=0; i<nums2.size(); i++){

                if(nums2[i]==x){

                    v.push_back(x);

                    nums2.erase(nums2.begin()+i);

                    break;

                }

            }

            j++;

        }

        return v;

    }

};

