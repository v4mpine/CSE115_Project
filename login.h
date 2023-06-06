#ifndef LOGIN_H
#define LOGIN_H
#include<stdio.h>
#include<string.h>

int checkLogin(char *username , char *password){
    char fileUsername[40];
    char filePassword[40];
    FILE *ptr;

    ptr = fopen("login.txt","r");

    if(ptr == NULL){
        printf("Can not open the file\n");

        return 0;
    }
    
    int flag = 0;

    fscanf(ptr,"%s %s",fileUsername,filePassword);

    if(strcmp(fileUsername,username)==0 && strcmp(filePassword,password)==0){
        flag = 1;
    }

    fclose(ptr);

    return flag;


    
}









#endif 