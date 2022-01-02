#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"reda.h"

void main(){
    int choice;
    FILE* read, *write;
    read = fopen("read.txt", "r");
    write = fopen("write.txt", "w+");
    bank crads = init(read, 3);
    print_bank(write, crads);
    // do{
    //     printf("0-Quitter\n1-Retrait\n2-Depot\nchoix=>");
    //     scanf("%d", &choice);
    //     // switch(choice){
    //     //     case 1:
    //     //         retrait()
    //     // }
    // }while(choice);
}