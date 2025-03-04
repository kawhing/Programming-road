#include <stdio.h>
#include <string.h>
//实现一个简单的银行账户管理系统，包括账户号码、账户名和账户余额，能够进行存款、取款和查询余额的操作

struct Bank_user
{
    long long user_number;
    long long id_card;
    char user_name[64];
    long long user_password;
    long long user_money; 
};

struct Bank_user bank_user[64];

long long user_numbers = 0;
long long number = 10001;

long long user_number;
long long user_money;
long long id_card;
char user_name[64];
long long user_password;



void sign_up();
void sign_in();
void forget_password();
void change_password();
void save_money(int i);
void withdrawals(int i);
void check_balance();
void verify();
void choice_1();
void choice_2(int i);




int main(){
    printf("Welcome to our banking systme! Have a good day!\n");
    printf("In our bank, you can register for a bank account, change your password, retrieve your password,\n");
    printf("check your balance, make deposits and withdrawals.\n");

    choice_1();
    return 0;
}

void verify(){
    int choice, tmp;
    printf("Which way to verify your identity?\nUser name or user number\n");
    printf("1. User name.\n2. User number.\n3. ID number.\n");
    scanf("%d",&choice);

    int test1 = 0, test2 = 0;
    if(choice == 1){
        printf("Please enter your user name :");
        scanf("%s",&user_name);

        for(int i = 0; i < user_numbers; ++i){
            if(strcmp(user_name, bank_user[i].user_name) == 0){
                tmp = i;
                test1 = 1;
            }
        }
    }else if(choice == 2){
        printf("Please enter your user nunmer : ");
        scanf("%lld",&user_number);
        for(int i = 0; i < user_numbers; ++i){
            if(user_number == bank_user[i].user_number){
                tmp = i;
                test1 = 1;
            }
        }
    }else if(choice == 3){
        printf("Please enter your ID number : ");
        scanf("%lld",&id_card);

        for(int i = 0; i < user_numbers; ++i){
            if(id_card == bank_user[i].id_card){
                tmp = i;
                test1 = 1;
            }
        }

    }

    if(test1 == 1){
        printf("Please enter your password : ");
        scanf("%lld",&user_password);
        for(int i = 0; i < user_numbers; ++i){
            if(user_password == bank_user[i].user_password){
                printf("Login successful!\n");
                test2 = 1; 
                break;
            }
        }
    }else{
        printf("We don't have the user name! Please enter again!\n");
        sign_in();
    }

    if(test2 == 1){
        printf("Welcome to your account systme!\nWhich is your want?\n");
        printf("1. Change password. \n2. Make deposits. \n3. Withdrawals. \n4. Check balance. \n5. Exit");
        printf("Please enter your choice :");
        scanf("%d",&choice);
        int i = tmp;
        switch(choice){
        case 1:
            change_password();
            break;
        case 2:
            save_money(i);
            break;
        case 3:
            withdrawals(i);
            break;
        case 4:
            check_balance();
            break;
        case 5:
            break;
        default:
            break;
        }
    } 
}



void sign_up(){
    printf("Welcome to the bank's account registration systme!\n");
    printf("We will guide you to register your account\n");

    printf("Please enter your ID number :");
    scanf("%lld",&bank_user[user_numbers].id_card);

    printf("Please enter your user name :");
    scanf("%s",bank_user[user_numbers].user_name);

    printf("Please enter you password :");
    scanf("%lld",&bank_user[user_numbers].user_password);

    char number_str[20];
    printf("Here is your user number : %lld\n",number);
    bank_user[user_numbers].user_number = number;

    ++user_numbers;
    ++number;
    
    printf("Successful register your account!\n");
}

void sign_in(){
    int choice;
    printf("Welcome to the bank's account login systme!");
    printf("We will giude you to login your account!\n");
    verify();
}

void forget_password(){
    int choice;
    long long tmp;
    printf("Which way to retrieve account by?\nUser name or user number\n");
    printf("1. User name.\n2. User number.\n3. ID number.\n");
    scanf("%d",&choice);

    int test1 = 0, test2 = 0;
    if(choice == 1){
        printf("Please enter your user name :");
        scanf("%lld",&user_name);

        for(int i = 0; i < user_numbers; ++i){
            if(strcmp(user_name, bank_user[i].user_name) == 0){
                tmp = i;
                printf("Please enter your ID number : ");
                scanf("%lld",&id_card);
                if(id_card == bank_user[i].id_card){
                    test1 = 1;
                    break;
                }
            }
        }
    }else if(choice == 2){
        printf("Please enter your user nunmer : ");
        scanf("%lld",user_number);
        for(int i = 0; i < user_numbers; ++i){
            if(user_number == bank_user[i].user_number){
                tmp = i;
                printf("Please enter your ID number :");
                scanf("%lld",&id_card);
                if(id_card == bank_user[i].id_card){
                    test1 = 1;
                    break;
                }
                
            }
        }
    }else if(choice == 3){
        printf("Please enter your ID number : ");
        scanf("%lld",&id_card);

        for(int i = 0; i < user_numbers; ++i){
            if(id_card == bank_user[i].id_card){
                tmp = i;
                test1 = 1;
            }
        }

    }
    if(test1 == 1){
        printf("You have certified that you are the owner of the account!\n");
        printf("Please enter new password for reset your password : ");
        scanf("%lld",&bank_user[tmp].user_password);
        printf("Successful to reset your password!\n");
        int i = tmp;
        choice_2(i);

    }
}
void change_password(){
    int tmp = 1, choice;
    printf("Please enter your ID number :");
    scanf("%lld",&id_card);

    for(int i = 0; i < user_numbers; ++i){
        if(id_card == bank_user[i].id_card){
            printf("Please enter new password for reset your password : ");
            scanf("%lld",&bank_user[i].user_password);
            printf("Successful to reset your password!\n");
            choice_2(i);
        }else{
            printf("ID number is wrong, please enter again!");
            if(tmp == 5){
                break;
                change_password();
                ++tmp;
            }
        }
    }

}
void save_money(int i){
    printf("Please enter the money you want to save : ");
    scanf("%lld",&user_money);
    bank_user[i].user_money += user_money;
    printf("Successful to save %lld!\n",user_money);
    choice_2(i);
}
void withdrawals(int i){
    printf("Please enter which money you want to withdrawal : ");
    scanf("%lld",user_money);
    if(user_money >= bank_user[i].user_money){
        bank_user[i].user_money -= user_money;
        printf("Successful to withdrawal %lld",user_money);
        choice_2(i);
    }else{
        printf("Your balance is not enough! Please reenter your withrawal money!\n");
        withdrawals(i);
    }
}
void check_balance(){
    for(int i = 0; i < user_numbers; ++i){
        printf("%lld\t    %lldt    %s\t    %lld\t    %lld\t\n",bank_user[i].user_number,bank_user[i].id_card,bank_user[i].user_name,bank_user[i].user_password,bank_user[i].user_money);
    }
}
void choice_1(){
    int choice;
    printf("1. Register your account. \n");
    printf("2. Login your account. \n");
    printf("3. Forget password. \n");
    printf("4. Change the password. \n");
    printf("5. Exit");
    printf("Please enter your choice :");

    scanf("%d",&choice);

    switch(choice){
    case 1:
        sign_up();
        break;
    case 2:
        sign_in();
        break;
    case 3:
        forget_password();
        break;
    case 4:
        change_password();
        break;
    case 5:
        break;
    default:
        break;
    }

    if(choice != 5){
        choice_1();
    }
}
void choice_2(int i){
    int choice;
    printf("Which is you want to do later?\n1. Change password.\n2. Make deposits.\n");
    printf("3. Withdrawals.\n4. Check balance.\n5. Exit");
    scanf("%d",&choice);
    
    switch(choice){
    case 1:
        change_password(i);
        break;
    case 2:
        save_money(i);
        break;
    case 3:
        withdrawals(i);
        break;
    case 4:
        check_balance(i);
        break;
    case 5:
        break;
    default:
        break;
    }    
}