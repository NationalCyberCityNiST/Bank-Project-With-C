#ifndef ONLINEBANK_H
#define ONLINEBANK_H
#include<stdio.h>
#include<stdlib.h>
#define USERSIZE 1000
#define DATA_COUNT 20


//global variable
int G_index=0; //for user counting
int email_found=-1; //for checking email exit
int space_array[DATA_COUNT];
int email_valid=-1;
int nrc_valid=-1;
int two_charArray=-1;

//end of global veriable

// function declartion
int check_input(char input[2]);
void login();
void rEgister();
int char_counting(char my_char[50]);
void loading_from_file();
void space_counter();
void printing_all_data();
void email_validation(char to_check[50]);
void email_exist_checking(char email[50]);
void nrc_validation(char nrc[20]);
void compare_two_charArray(char first[200],char second[200]);

struct trans{
    char note[200];
};
struct info{
    unsigned int id;
    char name[50];
    char nrc[20];
    char email[50];
    char password[50]; // strong password
    unsigned long long int phoneNumber;
    char encryption_key[50];//to encrypt user data
    char recovery_key[50];// for recover account
    char account_status[10];
    int account_type; // 1 for personal 2 for business 3 for others.....
    int account_level;
    int minimum_opening_deposit;
    char currency[5];
    unsigned long long int current_amount;//llu
    char loanStatus[1];
    unsigned int monthly_income;
    unsigned int loan_amount;
    double loan_rate;
    char address[100];

    struct trans tr[300];
    //%u%s%s%s%s%u%s%s%s%d%d%s%llu%s%u%u%f%s%s

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
     char re_email[50];
     char re_name[50];
     char re_nrc[20];

      printf("This is Online Bank Register !\n");
    email_valid=-1;
   while (email_valid==-1) {
        printf("Enter your email to register>>:");
        scanf(" %[^\n]", &re_email[0]);


        email_validation(re_email);
        if (email_valid == -1) {
            printf("Your email format was not valid\n");
        }
    }
    printf("Your email form was valid:\n");
    email_found=-1;
    email_exist_checking(re_email);
    if( email_found !=-1 ){
        printf("Your email was already register:\n");
        rEgister();
    } else{
        printf(" Del re_email %s\n",re_email);
        printf("Your email was saved:\n");
        printf("Enter your username:\n");
        scanf(" %[^\n]",&re_name[0]);
        nrc_valid=-1;

        while (nrc_valid==-1){

            printf("Enter your NRC information:");
            scanf(" %[^\n]",&re_nrc[0]);

            nrc_validation(re_nrc);

            if(nrc_valid==-1){
                printf("Your NRC Format was incorrect!\n");
            }

        }
        
        printf("[+]Your NRC format was correct:\n");
        printf(" del re_nrc test: %s",re_nrc);
        
        
    }
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
void loading_from_file(){

    FILE *fptr = fopen("database.txt","r");

    if( fptr != NULL){

        for(register int user=0; user < USERSIZE ; user++){

            fscanf(fptr ,"%u%s%s%s%s%u%s%s%s%d%d%d%s%llu%s%u%u%f%s",&db[user].id ,&db[user].name ,&db[user].nrc,&db[user].email,&db[user].password,&db[user].phoneNumber,&db[user].encryption_key,&db[user].recovery_key,&db[user].account_status,&db[user].account_type,&db[user].account_level,&db[user].minimum_opening_deposit,&db[user].currency,&db[user].current_amount,&db[user].loanStatus,&db[user].monthly_income,&db[user].loan_amount,&db[user].loan_rate,&db[user].address);

            for(register int trc=0; trc<= space_array[user]-19 ; trc++ ){
                fscanf(fptr , "%s",&db[user].tr[trc].note[0]);
            }
            if(db[user].id == 0){
                break;
            }
            G_index++;

        }

    } else{
        printf("File opening error at Loading form file function!\n");
    }

    fclose(fptr);
}

void space_counter(){

    FILE *fptr = fopen("database.txt","r");

    if(fptr != NULL){
        char c = fgetc(fptr);
        int index=0;

        while (!feof(fptr)){
            if(c != '\n'){

                if( c == ' '){
                    space_array[index] +=1;

                }
                c = fgetc(fptr);

            } else{

                index++;
                c = fgetc(fptr);
            }

        }

    } else{
        printf("File open error at space_counter fun()\n");
    }

    for(int i=0; i<DATA_COUNT; i++){

        printf(" %d",space_array[i]);
    }
    printf("\n");

}
void printing_all_data() {


    for (int user = 0; user < G_index; user++) {

        printf("%u-%s-%s-%s-%s-%llu-%s-%s-%s-%d-%d-%d-%s-%llu-%s-%u-%u-%f-%s", db[user].id, db[user].name, db[user].nrc,
               db[user].email, db[user].password, db[user].phoneNumber, db[user].encryption_key, db[user].recovery_key,
               db[user].account_status, db[user].account_type, db[user].account_level, db[user].minimum_opening_deposit,
               db[user].currency, db[user].current_amount, db[user].loanStatus, db[user].monthly_income,
               db[user].loan_amount, db[user].loan_rate, db[user].address);
        for (int gcc = 0; gcc <= space_array[user] - 19; gcc++) {
            printf("-%s", db[user].tr[gcc].note);
        }
        printf("\n");

    }
}

void email_validation(char to_check[50]){

    int space=1;
    int format=1;
    char valid_form[10]={'@','g','m','a','i','l','.','c','o','m'};
    int check_counter = char_counting(to_check);

    int front_counter = check_counter-10;

    for(int i=0; i<front_counter ; i++){
        if(to_check[i]==' '){
            space=-1;
            break;
        }
    }
    for(int f=0; f<10; f++){
        if(to_check[front_counter] != valid_form[f]){
            format = -1;
            break;
        }
        front_counter++;
    }

    if(space == 1 && format==1){
        email_valid=1;
    }
}
void email_exist_checking(char email[50]){
    int counter = char_counting(email);//for user input email
    int same_counting=0;

    for(register int gcc=0; gcc<G_index ; gcc++){
        int email_count =char_counting(db[gcc].email); // for email from db;
        same_counting=0;
        if( counter == email_count ){
            for( register int a=0; a<counter ; a++){
                if(email[a] != db[gcc].email[a]){
                    break;
                }
                same_counting++;
            }
        }
        if( counter == same_counting){
            email_found=gcc;
        }
    }

}
void nrc_validation(char nrc[20]){

    int nrc_counter = char_counting(nrc);

    for(int i=0; i<3; i++){

        two_charArray=-1;
        compare_two_charArray(nrc,db[i].nrc);
        if(two_charArray ==1){
            nrc_valid=1;
            break;
        }


    }

}

void compare_two_charArray(char first[200],char second[200]){

    int first_counter = char_counting(first);
    int second_counter = char_counting(second);

    int same_counter=0;

    if(first_counter == second_counter){

        for(register int i=0; i<first_counter; i++){

            if(first[i] != second[i]){
                break;
            }
            same_counter++;
        }

        if(first_counter == same_counter){
            two_charArray = 1;

        }

    }


}


#endif // ONLINEBANK_H
