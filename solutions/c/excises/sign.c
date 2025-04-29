#include <stdio.h>
#include <string.h>

struct Sign {
    char user_name[10];
    long long user_password;
};

struct Sign sign[64];
int user_number = 0;
char user_name[10];
long long user_password;
int tmp;

void sign_up();
void sign_in();
void find_user_name();
void find_user_password();
void choice();



void sign_up(){   
    printf("Please enter you user name : \n");
    scanf("%s",sign[user_number].user_name);
    printf("Please enter your password : \n");
    scanf("%lld",&sign[user_number].user_password);
    ++user_number;
    printf("Successful registration\n");

    choice();
}

void find_user_name(){
    printf("Please enter your user name\n : ");
    scanf("%s",user_name);
    
    int test = 0;
    for(int i = 0; i < user_number; ++i){
        if(strcmp(sign[i].user_name, user_name) == 0){
            tmp = i;
            test = 1;
            find_user_password();
        }
    }
    if(test == 0){
        fflush(stdin);
        printf("Invalid user name, plese enter again or exit software");
        printf("1. Enter again. \n");
        printf("2. Exit the software. \n");
        printf("Please enter your choice\n : ");
            
        int choice;
        scanf("%d",&choice);
            
        switch(choice){
            case 1:
            find_user_name();
            break;
                
            case 2:
            break;
                
            default:
            break;
        }
    }
}
void find_user_password(){
    printf("Please enter your password. : \n");
    scanf("%lld",&user_password);
    
    if(user_password == sign[tmp].user_password){
        printf("Successful sign in\n");
    }else{
        int choice;

        printf("Invalid password, you could try enter again or exit the software. \n");
        printf("1. Enter again.\n");
        printf("2. Exit. \n");
        printf("Please choose your choice\n");

        scanf("%d",&choice);
        switch(choice){
            case 1:
            find_user_password();
            break;
            
            case 2:
            break;
            
            default:
            break;
        }
    }
}

void sign_in(){
    find_user_name();
    choice();
}

void choice(){
    int i;
    printf("Velcome the software : \n");
    printf("1. Sign up\n");
    printf("2. Sign in\n");
    printf("3. Exit the software.\n");
    printf("Please enter your choice\n");

    scanf("%d",&i);
   

    switch(i){
        case 1:
        sign_up();
        break;

        case 2:
        sign_in();
        break;

        case 3:
        break;

        default :
        break;

        
    }
}

int main() {
    choice();
    return 0;
}