#include <stdio.h>
#include <string.h>
//一个简单的电话簿程序，可以添加、删除、查找和显示联系人信息

struct Phone{
    char name[64];
    long number;
};

struct Phone phone[64];
int numbers = 0;

int contact_number;
char name[64];
long number;

void add();
void delete();
int find();
void lookup();
void display();
void choice();


int main(){
    printf("Welcome the phonebox software!\n");
    choice();
}

void add(){
    printf("Please enter a contact's information\n");
    printf("Name : \n");
    scanf("%s",phone[numbers].name);
    printf("Phone number : ");
    scanf("%ld",&phone[numbers].number);
    ++numbers;
}

void delete(){
    int choice;
    dispaly();
    printf("Please enter the contact which is you want to delete.\n");
    printf("1. contact number.\n2. Name.\n3. Phone number.\n");
    scanf("%d",&choice);
    
    int test = find(choice);
    
    for (int i = test; i < numbers; ++i){
        phone[i] = phone[i+1];
    }
    --numbers;
}

int find(int choice){
    int test = 0;
        if (choice == 1){
            printf("Please enter the contact number : ");
            scanf("%d",&contact_number);
            for(int i = 0; i < numbers; ++i){
                if(contact_number == i+1){
                    return i;
                }
            }
        }else if (choice == 2){
            printf("Please enter the contact's name : ");
            scanf("%s",name);

            for (int i = 0; i < numbers; ++i){
                if (name == phone[i].name){
                   return i;
                }
            }
        }else if (choice == 3){
            printf("Please enter the number : ");
            scanf("%ld",&number);

            for (int i = 0; i < numbers; ++i){
                if (number == phone[i].number){
                   return i;
                }
            }
        }    
}
void lookup(){
    int test = find(choice);
    printf("%d\t.     %s\t     %ld\t\n",test+1 ,phone[test].name, phone[test].number);
}
void display(){
    for (int i = 0; i < numbers; ++i){
        printf("%d\t.     %s\t     %ld\t\n",i+1 ,phone[i].name, phone[i].number);
    }
}

void choice(){
    int choices;
    printf("What are you want to do about here?\n");
    printf("1. Add a contact.\n2. Delete a contact.\n3. Lookup a contact.\n4.Display a contact\n5. Exit.\n");
    printf("Please enter your choice : ");

    scanf("%d",&choice);
    switch (choices){
    case 1:
        add();
    case 2:
        delete();
    case 3:
        lookup();
    case 4:
        display();
    case 5:
        break;
    default :
        break;
    }
    
    if(choice != 5){
        choice();
    }

}