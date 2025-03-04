#include <stdio.h>
#include <string.h>
//实现一个简单的图书管理系统，包括书名、作者和出版日期，能够添加书籍、删除书籍和显示所有书籍信息的功能

struct Book{
    char book_name[64];
    char book_writer[64];
    char book_date[64];
};

struct Book book[64];

int book_number = 0;
char book_name[64];
char book_writer[64];
char book_date[64];

//声明定义的函数
void add_book();
void delete_book();
void display_book();
void choice();
void clearInputBuffer();

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//添加书籍函数
void add_book(){
    printf("Please enter the book's name whice is you want to add :\n");
    clearInputBuffer();
    fgets(book[book_number].book_name, 64, stdin);
    

    printf("Please enter the book's writer : \n");
    fgets(book[book_number].book_writer,64,stdin);
    

    printf("Please enter the book's date : \n");
    fgets(book[book_number].book_date, 64, stdin);
    

    printf("Successful to add the book's information!\n");
    ++book_number;

    printf("Please enter what do want to do later :\n");
    choice();
}

//删除书籍函数
void delete_book(){
    int choice, test = 0;
    printf("Please enter the book's name which you want to delete : \n");
    clearInputBuffer(); // Clear input buffer before reading book name
    fgets(book_name, 64, stdin);

    for(int i = 0; i < book_number; ++i){
        if(strcmp(book_name, book[i].book_name) == 0){
            printf("Do you really want to delete the book?\n");
            printf("1. I really want to delete the book. \n");
            printf("2. No, I'm canceling the deletion. \n");
            printf("Please enter the number before the following options : \n");
            
            scanf("%d",&choice);

            switch(choice){
                case 1:
                    test = 1;
                    break;

                case 2:
                    break;

                default:
                    printf("Input not legal!\n");
                    break;
            }

            if(test == 1){
                for(int j = i; j < book_number - 1; ++j){ // Fix the loop condition
                    book[j] = book[j+1];
                }
                --book_number;
                printf("Successful to delete the book from the database!\n");
            }else{
                printf("Go back to the main menu screen now!\n");
            }
            break; // Exit the loop after deleting the book
        }
    }
}

void display_book(){
    printf("Here are the book's database information : \n");
    for(int i = 0; i < book_number; ++i){
        printf("%d. name : %s\t     writer : %s\t     date : %s\t\n",i+1,book[i].book_name,book[i].book_writer, book[i].book_date);
    }
}

void choice(){ 
    int choices;
    printf("1. Add books. \n");
    printf("2. Delete books. \n");
    printf("3. Dispaly the books. \n");
    printf("4. Exit.\n");
    printf("Please enter your choice : \n");
    scanf("%d",&choices);

    switch(choices){
        case 1:
        add_book();

        case 2:
        delete_book();

        case 3:
        display_book();

        case 4:
        break;

        default:
        break;
    }
    if(choices != 4){
        choice();
    }

}
int main(){
    printf("Velcome to our library managerment system! \n");
    printf("You can do the folowing in this systeme :\n");
    choice();
}
