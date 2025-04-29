#include<stdio.h>
#include<string.h>
#define MAX_STUDENT 10


struct Student{
    long long id;
    char name[5];
    int score;
};


struct Student student[MAX_STUDENT];
int num_student = 0;

void addStudent(){
    if(num_student < MAX_STUDENT){
        struct Student new_Student;


        printf("Please enter a student ID : \n");
        scanf("%lld",&new_Student.id);

        printf("Please enter the student's name : \n");
        scanf("%s",&new_Student.name);

        printf("Please enter the student score : \n");
        scanf("%d",&new_Student.score);


        student[num_student] = new_Student;
        ++num_student; 
    }
}


void deleteStudent(){
    int id;
    printf("Please enter the student's ID to delete : ");
    scanf("%d",&id);

    int found = 0;
    for(int i = 0; i < num_student; ++i){
        if(student[i].id == id){
            found = 1;

            for(int j = i; j < num_student; ++j){
                student[j] = student[j+1];
            }
            --num_student;
            printf("Deleter the student successfully!\n");
            break;
        }
    }

    if(!found){
        printf("No found the student!\n");
    }
}


void displayStudents(){
    if(num_student == 0){
        printf("These have no student\n");
    }else{
        printf("Students' information : \n");
        printf("ID\tName\tScore\n");
        for(int i = 0; i < num_student; ++i){
            printf("%-6lld\t%-10s\t%-5d\n",student[i].id,student[i].name,student[i].score);
        }
    }
}
void choice(){
    printf("Velcome the single students' database,hear are 4 choice which you should have make :\n");
    printf("1. Add new student to the database. \n");
    printf("2. Delete student's data from database.\n");
    printf("3. Display the students' database.\n");
    printf("4. Exit the program.\n");
    int choices;
    scanf("%d",&choices);
    
    switch(choices){
        case 1:
        addStudent();
        break;

        case 2:
        deleteStudent();
        break;

        case 3:
        displayStudents();
        break;

        case 4:
        break;

        default:
        printf("Invalid choice,please try enter again\n\n\n");
    }
    if(choices != 4){
        choice();
    }
   
}

int main(){
    choice();
    return 0;
}