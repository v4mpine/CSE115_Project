#ifndef MENU_H
#define MENU_H

#include<stdio.h>

typedef struct sea{
    char name[50];
    int stock;
    int price;
    float weight;
}fish;

void viewFish(void);

void menu(void){
    printf("Welcome to the menu......\n");
    printf("\n");
    int flag = 0;
    int choice;

    while(1){
        printf("\n\n");
        printf("1.View all fish\n");
        printf("2.Add fish\n");
        printf("3.Buy fish\n");
        printf("4.Search fish\n");
        printf("5.Terms & Policy\n");
        printf("6.Exit\n");
        printf("\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("\n\n");

        switch(choice){
            case 1: 
                    viewFish();
                    break;

            case 5: 

            case 6: 
                    printf("Thank you for buying fish from us\n");
                    printf("Have a good day\n");
                    flag = 1;
                    break;

            default: 
                    printf("Invalid choice.Try again!!!\n");
                    break;
                     
        }
        printf("\n");

        if(flag == 1){
            break;
        }
        
    }
}

void viewFish(void){
    fish s1;

    FILE *ptr;

    ptr = fopen("menu.txt","r");

    if(ptr == NULL){
        printf("Can not open the file\n");

        return;
    }

    printf("Name\tStock\tPrice\tWeight\n");
    printf("\n");

    while (fscanf(ptr, "%s\t%d\t%d\t%f\n", s1.name, &s1.stock, &s1.price, &s1.weight) == 4) {
        printf("%s\t%d\t%d\t%.2f\n", s1.name, s1.stock, s1.price, s1.weight);
    }
    fclose(ptr); 

}




#endif