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

    char ch;

    while((ch = fgetc(ptr))!= EOF){
        fprintf(stdout,"%c",ch);
        usleep(5000);   
    }

    fclose(ptr);





}

#endif