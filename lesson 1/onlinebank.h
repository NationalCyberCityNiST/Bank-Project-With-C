#ifndef ONLINEBANK_H
#define ONLINEBANK_H
#include<stdio.h>
#include<stdlib.h>


// function declartion
int check_input(char input[2]);
void login();
void rEgister();
int char_counting(char my_char[50]);


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
