class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sandwichesStack;
        queue<int> studentsQueue;
        for(int i = 0; i < students.size(); ++i){
            studentsQueue.push(students[i]);
        }
        for(int i = students.size() - 1; i >= 0; --i){
            sandwichesStack.push(sandwiches[i]);
        }
        int count = 0;
        while(count != studentsQueue.size()){
            if(studentsQueue.front() == sandwichesStack.top()){
                sandwichesStack.pop();
                studentsQueue.pop();
                count = 0;
            }else{
                int student = studentsQueue.front();
                studentsQueue.pop();
                studentsQueue.push(student);
                ++count;
            }
        }
        return studentsQueue.size();
    }
};