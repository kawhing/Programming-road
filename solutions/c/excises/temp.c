// // int myAtoi(char* s) {
// //     int len = strlen(s);
// //     int result = 0;
// //     for(int i = 0; i < len; ++i){
// //         if(result == 0){
// //             if(s[i] > '0' && s[i] <= '9'){
// //                 result = result * 10 + s[i];
// //             }else if(s[0] == 0){
// //                 s[i] == '-';
// //                 return 0;
// //             }else if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
// //                 return 0;
// //             }
// //         }else {
// //             if(s[i] >= '0' && s[i] < '9'){
// //                 result = result*10 + s[i];
// //             }
// //         }

// //     }
// //     if(result > 0 && s[0] == '-'){
// //         result = - result;
// //     }
// //     return result;
// // }
// // #include <stdio.h>

// // int main(){

//     // int a[] = {2,3,5,9}, *pa = a, w;
//     // w = ++(*++pa);
//     // int y = 2;
//     // y += y *= *y + 1;
//     // float a[3] = {1.5, 2.5, 3.5};
//     // float *pa = a;
//     // *(pa++)*=3;
//     // printf("%f",*pa);
//     // int a = 2, *p1, **p2;
//     // p2 = &p1;
//     // p1 = &a;
//     // ++a;
//     // printf("%d %d %d", a, *p1, **p2);


// //     struct st{
// //         int num;
// //         char name[10];
// //         int age
// //     }x[3] = {{1,"zhang",19},{2,"li", 20},{3,"wang",21}}, *p=x;
// // void main(){
// //     printf("%s,%d\n", (p+2)->name,(*p).age);
// // }



// /*
// #include <math.h>

// int main(){
//     float x, y;
//     printf("请输入一个数字 : ");
//     scanf("%f", &x);

//     if(x < -2){
//         y = pow(x, 2) - sin(x);
//     }else if (x >= -2 && x <= 2){
//         y = pow(2, x) + x;
//     }else{
//         y = sqrt(pow(x, 2) + x + 1);
//     }

//     printf("y = %f\n",y);
//     return 0;
// }
// */

// /*
// struct Student{
//     int number;
//     char name[10];
//     float score;
// };

// struct Student student[10];

// void top_student(int len){
//     int top = 0;
//     for(int i = 1; i < len; ++i){
//         if(student[i].score > student[top].score){
//             top = i;
//         }
//     }

//     printf("最高分学生的学号 : %d\n", student[top].number);
//     printf("最高分学生的姓名 : %s\n", student[top].name);
//     printf("最高分学生的成绩 : %f\n", student[top].score);
// }
// float average(int len){
//     float average_score = 0;
//     for(int i = 0; i < len; ++i){
//         average_score += student[i].score;
//     }
//     return average_score/len;
// }

// int main(){
//     int len = 10;
//     printf("请输入学生的学号，姓名，成绩：\n");
//     for(int i = 0; i < len; ++i){
//         printf("第%d个学生 : \n", i+1);
//         printf("学号 : ");
//         scanf("%d",&student[i].number);
//         printf("姓名 : ");
//         scanf("%s", student[i].name);
//         printf("成绩 : ");
//         scanf("%f",&student[i].score);
//     }
    
//     top_student(len);
//     printf("\n平均成绩为 : %f\n", average(len));
// }
// */
// #include <stdio.h>
// int juge(int number, int j);
// int main() {
//     printf("请输入一个正整数 : ");
//     int number;
//     scanf("%d", &number);

//     // FILE *file;
//     // file = fopen("D:\\hello.text", "w");
//     // if(file == NULL){
//     //     printf("文件打开失败\n");
//     // }else{
//     //     int test = 0;
//     //     printf("文件打开成功\n");
//     //     for(int  i = 1; i < number; ++i){
//     //         juge(number, i);
//     //     }
//     //     fclose(file);
//     //}

//     for(int  i = 1; i <= number; ++i){
//         printf("%d ",juge(number, i));
//     }
//     return 0;
// }

// int juge(int number, int j ){
    
//     for(int num1 = j-1; num1 > 0 && num1 >= 1; --num1){
//         for(int num2 = num1-1; num2 != num1 && num2 > 0 && num2 >= 1; --num2){
//             for(int num3 = num2-1; num3 != num2 && num3 > 0 && num3 >= 1; --num3){
//                 if(j == num1+num2+num3){
//                    return j;
//                 }
//             }
//         }
//     }
// }

#include <stdio.h>

int main(){
    int x = 11;
    printf("%d ", x++ *1/3);
    return 0;
}

