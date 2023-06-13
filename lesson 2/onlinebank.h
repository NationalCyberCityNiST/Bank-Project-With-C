#ifndef ONLINEBANK_H
#define ONLINEBANK_H
#include<stdio.h>
#include<stdlib.h>
#define USERSIZE 1000
//global variable
int G_index=0; //for user counting
int email_found=-1; //for checking email exit

//end of global veriable

// function declartion
int check_input(char input[2]);
void login();
void rEgister();
int char_counting(char my_char[50]);
struct trans{
    char note[200];
};

struct info{
unsigned int id;// user id
 char name[50];
 char  nrc[20];
char email[50];
char password[50];
unsigned int phoneNumber;
char encryption_key[50]; //
char recovery_key[50];
 int account_type; //1 personal, 2 business, 3 other.
char account_status[10];
int account_level;
int minimum_opening_deposit;
char currency[5];
unsigned long long int current_amount;
char loanStatus[1];
unsigned int monthly_income;
unsigned int loan_amount;
float loan_rate;
char address[100];

struct trans tr[300];

};

struct info db[USERSIZE];


void main_menu(){
    char input[2];
    printf("Welcome to our bank\n");
    printf("Press 1 to login\nPress 2 to Register\nPress 3 to Exit\n");
    scanf(" %[^\n]",&input);
   int option= check_input(input);
    if(option==49){
        login();
    }else if(option==50){
        rEgister();
    }else if(option==51){
        printf("exit");
        exit (2);
    }else{
        main_menu();
    }

}
// ascii value 0=48 & 9=57
int check_input(char input[2]){
    if( input[0]>=49 && input[0]<=57 && input[1]=='\0'){
        return input[0];
    }else{
        return-1;
    }
}

void login(){
    char l_email[50];
    printf("This is online bank login\n");
    printf("Enter your email to login\n");
    scanf(" %[^\n]",&l_email);
}
void rEgister(){
    char r_email[50];
     printf("This is online bank register\n");
    printf("Enter your email to register\n");
    scanf(" %[^\n]",&r_email);
    
}


void email_exit_checking(char email[50]){
    int counter=char_counting(email);
    int same_counting=0;
    for(register int gcc=0;gcc<G_index;gcc++){
        int db_email_count=char_counting(db[gcc].email);
        if(counter==db_email_count){
            for(register int a=0;a<counter;a++){
                if(email[a]!=db[gcc].email[0]){
                    break;
                }
                same_counting++;
            }
        }
        if(counter==same_counting){
        email_found=gcc;
    }
    }

}

int char_counting(char my_char[50]){
    int count=0;
for(register int a=0;a<50;a++){
    if(my_char[a]=='\0'){
        break;
    }count++;
}
return count;

}

#endif // ONLINEBANK_H
