#include<stdio.h>
#include<dos.h>
#include"splash.h"
#include"login.h"

typedef struct {
     
     char username[40];
     char password[40]; 

 }login;

int main(void){

   
   printSplashScreen();
   sleep(5);
   system("cls");

    login check;

    while(1){
        printf("Enter Username:");
        scanf("%s",check.username);

        printf("Enter Password:");
        scanf("%s",check.password);

        if(checkLogin(check.username,check.password)==1){
            printf("Login Successful!!!\n");
            break;
        }
        else{
            printf("Invalid username or password.Try again!!\n");
        }
    }
   
    return 0;
}