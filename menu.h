#ifndef MENU_H
#define MENU_H


#include<stdio.h>
#include<stdlib.h>




typedef struct {
    char name[50];
    int stock;
    int price;
    float weight;
}fish;

void viewFish(void);
void addFish(void);
void buyFish(void);
void billSlip(void);





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
        printf("4.Bill slip\n");
        printf("5.Terms and Policies\n");
        printf("6.Exit\n");
        printf("\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("\n\n");

        switch(choice){
            case 1:
                    viewFish();
                    break;

            case 2:
                    addFish();
                    break;

            case 3:
                    while (1) {
                            buyFish();
                            printf("Press any key to buy more fish or 'Enter' to stop buying...\n");
                            fflush(stdin);
                            if (getch() == '\r')
                                break;

                }
                break;
            case 4:
                    billSlip();
                    printf("\n\n\n");
                    printf("Thank you for buying fish from us\n");
                    printf("Have a good day\n");
                    break;

            case 5:
                    system("F:\\Project\\CSE115_Project\\trade_image.jpeg");
                    break;

            
            case 6:
                    flag = 1;
                    break;
            default:
                    printf("Invalid choice.Try again!!!\n");
                    break;

        }
        printf("\n");

        if(flag == 1){
           remove("buyfish.txt");
           break;

        }

    }
}



void viewFish(void){
    fish s1;

    FILE *ptr;

    ptr = fopen("menu.txt","r");

    if(ptr ==   NULL){
        printf("Can not open the file\n");

        return;
    }

    printf("Name\t\tStock\tPrice\tWeight(gm)\n");
    printf("\n");

    while (fscanf(ptr, "%s\t\t%d\t%d\t%f\n", s1.name, &s1.stock, &s1.price, &s1.weight) == 4) {
        printf("%s\t\t%d\t%d\t%.2f\n", s1.name, s1.stock, s1.price, s1.weight);
    }
    fclose(ptr);

}

void addFish(void){

    fish s2;

    FILE *ptr;

    ptr = fopen("menu.txt","a");

    if (ptr == NULL) {
        printf("Cannot open the file\n");
        return;
    }

    printf("Enter the name of the fish: ");
    scanf("%s", s2.name);

    printf("Enter the stock of the fish: ");
    scanf("%d", &s2.stock);

    printf("Enter the price of the fish: ");
    scanf("%d", &s2.price);

    printf("Enter the weight of the fish: ");
    scanf("%f", &s2.weight);

    fprintf(ptr, "%s\t\t%d\t%d\t%.2f\n", s2.name, s2.stock, s2.price, s2.weight);

    fclose(ptr);

    printf("\n");

    printf("Fish added successfully!\n");
}

void buyFish(void){
    char fishName[50];
    int quantity;

    printf("Enter the name of the fish you want to buy: ");
    scanf("%s", fishName);

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    FILE* menuPtr;
    FILE* buyPtr;
    FILE* tempPtr;

    menuPtr = fopen("menu.txt", "r");
    buyPtr = fopen("buyfish.txt", "a");
    tempPtr = fopen("temp.txt", "w");

    if (menuPtr == NULL || buyPtr == NULL || tempPtr == NULL) {
        printf("Cannot open the file\n");
        return;
    }

    fish s3;
    int found = 0;

    while (fscanf(menuPtr, "%s\t\t%d\t%d\t%f\n", s3.name, &s3.stock, &s3.price, &s3.weight) == 4) {
        if (strcmp(s3.name, fishName) == 0) {
            found = 1;
            if (s3.stock >= quantity) {
                s3.stock -= quantity;
                printf("Fish bought successfully!\n");
                fprintf(buyPtr, "%s\t\t%d\t%d\t%.2f\n", s3.name, quantity, s3.price, s3.weight);
            } else {
                printf("Not enough stock available for the selected fish.\n");
            }
        }
        fprintf(tempPtr, "%s\t\t%d\t%d\t%.2f\n", s3.name, s3.stock, s3.price, s3.weight);
    }

    fclose(menuPtr);
    fclose(buyPtr);
    fclose(tempPtr);

    if (!found) {
        printf("Fish not found in the menu\n");
        remove("temp.txt");
    } else {
        remove("menu.txt");
        rename("temp.txt", "menu.txt");
    }
}

void billSlip(void){

    fish s4;

    FILE* buyPtr;

    buyPtr = fopen("buyfish.txt", "r");

    if (buyPtr == NULL) {
        printf("Can not open the file\n");
        return;
    }

    int totalPrice = 0;

    printf("\n\nBill Slip\n");
    printf("--------------\n");

    while (fscanf(buyPtr, "%s\t\t%d\t%d\t%f\n", s4.name, &s4.stock, &s4.price, &s4.weight) == 4) {
        int price = s4.price * s4.stock;
        printf("\nFish Name: %s\n", s4.name);
        printf("Price per piece: %d\n", s4.price);
        printf("Quantity: %d\n", s4.stock);
        printf("Total Price: %d\n", price);
        totalPrice += price;
    }

    fclose(buyPtr);

    printf("\nTotal Bill: %d\n", totalPrice);
}




#endif
