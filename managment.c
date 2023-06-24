#include<stdio.h>
#include<dos.h>
#include"splash.h"
#include"login.h"
#include"menu.h"




int main(void){


    printSplashScreen();
    sleep(5);
    system("cls");
    
    LoginProcess();
    system("cls");
    menu();
   
   

   
    return 0;
}