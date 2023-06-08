#ifndef SPLASH_H
#define SPLASH_H

#include <stdio.h>
#include<unistd.h>


void printSplashScreen(void){


    FILE *ptr;

    ptr = fopen("splash.txt","r");

    if(ptr == NULL){
        printf("Failed to open the file \n");
        return ;
    }

    char ch[300];
   
    while(fgets(ch,300,ptr)){
        printf("%s",ch);
        usleep(100000);
    }

    fclose(ptr);

}

#endif