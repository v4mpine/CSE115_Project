#ifndef LOGIN_H
#define LOGIN_H
#include<stdio.h>
#include<string.h>


/*
Username and Password  string is in a structure  
*/
typedef struct{
    char username[100]; // having a big size of a string
    char password[100];

}login;


void LoginProcess(void);
int checkLogin(char *username , char *password);
int createAccount(char *username, char *password);

void LoginProcess(void){
     
    login user;
   
    int flag = 0;
    int choice;
    
    while(1){
            printf("1.Login\n");
            printf("2.Create a new account\n");
            printf("\n");
            printf("Enter your choice:");
            scanf("%d",&choice);
            printf("\n");
            switch(choice){
                case 1:
                       printf("Enter your username: ");
                       scanf("%s",user.username);

                       printf("Enter your password: ");
                       scanf("%s",user.password);

                       if(checkLogin(user.username,user.password)){
                          printf("Login successful!\n");
                          flag = 1;
                       }
                       else{
                        printf("Username or Password is invalid\n");
                       }
                       break;
                case 2:
                       printf("Enter your username: ");
                       scanf("%s",user.username);

                       printf("Enter your password: ");
                       scanf("%s",user.password);

                       if(createAccount(user.username,user.password)){
                          printf("Account created successfully\n");
                       }
                       else{
                        printf("Something went wrong\n");
                       }
                       break;
                default:
                        printf("Invalid choice.Please try again");
                        break;
                      
            }

            if(flag == 1){
                break;
            }
            printf("\n");

        }
}
int checkLogin(char *username , char *password){
    
    login check;
    
    FILE *ptr;

    ptr = fopen("login.txt","r");

    if(ptr == NULL){
        printf("Can not open the file\n");

        return 0;
    }
    
    int flag = 0;

    while(fscanf(ptr,"%s\n%s\n",check.username,check.password) == 2){
    if(strcmp(check.username,username) == 0 && strcmp(check.password,password) == 0){
        flag = 1;
        break;
      }
    }

    fclose(ptr);

    return flag;
}
int createAccount(char *username, char *password){
    
    FILE *fptr;

    fptr = fopen("login.txt","a");

    if(fptr == NULL){
        printf("Can not open the file\n");

        return 0;
    }

    fprintf(fptr,"%s\n%s\n",username,password);

    fclose(fptr);

    return 1;

}

#endif 
