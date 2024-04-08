class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
         int student_zero=0;
         int student_one=0;
         for(int i=0;i<students.size();i++){
              if(students[i]==0){
                student_zero++;
              }
              else{
                student_one++;
              }
         }

          int sandwiches_zero=0;
          int sandwiches_one=0;
          for(int i=0;i<sandwiches.size();i++){
              if(sandwiches[i]==0){
                sandwiches_zero++;
              }
              else{
                sandwiches_one++;
              }
         }

          int i=0;
         for(;i<sandwiches.size();i++){
             if(sandwiches[i]==0 && student_zero > 0){
                 student_zero--;
             }
             else if (sandwiches[i]==1 && student_one > 0){
                student_one--;
             }
             else {
                 break;
             }
         }
         return sandwiches.size() - i;
       
    }
};
