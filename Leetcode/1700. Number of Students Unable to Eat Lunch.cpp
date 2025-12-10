class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> student;
        stack<int> sandwich;

        for(int i=0;i<students.size() ; i++)
        student.push(students[i]);

        for(int j = sandwiches.size() -1; j>=0 ; j--)
        sandwich.push(sandwiches[j]);

        int k = 0;


        while(!sandwich.empty() && !student.empty()){
            if(student.front() == sandwich.top()){
                student.pop();
                sandwich.pop();
                k=0;
            }
            else{
                int temp = student.front();
                student.pop();
                student.push(temp);
                k++;
            }

            if(k == student.size())
            break;
        }

        return student.size();
    }
};