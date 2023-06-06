#include<stdio.h>
#include<dos.h>
#include"splash.h"
#include"login.h"

int main(void){

   
   printSplashScreen();
   sleep(5);
   system("cls");

   char username[40];
   char password[40]; 

    while(1){
        printf("Enter Username:");
        scanf("%s",username);

        printf("Enter Password:");
        scanf("%s",password);

        if(checkLogin(username,password)==1){
            printf("Login Successful!!!\n");
            break;
        }
        else{
            printf("Invalid username or password.Try again!!\n");
        }
    }
   
    return 0;
}