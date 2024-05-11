#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <graphics.h>
#include "base.h"
#include "add_and_del.h"
#include "graphic.h"
#include "save_and_read.h"
#include "sort.h"
//Zakharow Timofey 123-mm
int main() {
    int choice, index, field, direction, chartType, file;
    char filename[50];
    while (1) {
        display_menu();
        printf("\n Make a choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                print_table();
                break;
            case 2:
                add_object();
                break;
            case 3:
                printf("Input index of object to be deleted: ");
                scanf("%d", &index);
                delete_object(index);
                break;
            case 4:
                printf("Choose: 1 save object in file \n2 rename file\n");
                scanf("%d", &file);
                switch (file) {
                    case 1:
                        saveToFile("objects.txt");
                        break;
                    case 2:
                        printf("Input file name: ");
                        scanf("%s", filename);
                        saveToFile(filename);
                        break;
                    default:
                        printf("Input error\n");
                }
                break;
            case 5:
                printf("Choose: 1 read from exact file \n2 rename file\n");
                scanf("%d", &file);
                switch (file){
                    case 1:
                        readFromFile("objects.txt");
                        break;
                    case 2:
                        printf("Input file name: ");
                        scanf("%s", filename);
                        readFromFile(filename);
                        break;
                    default:
                        printf("Input error\n");
                }
                break;
            case 6:
                printf("Choose sorting (1 - text, 2 - double num, 3 - int num): ");
                scanf("%d", &field);
                printf("Choose sorting order (1 - up, 2 - down): ");
                scanf("%d", &direction);
                if (direction>2){
                    printf("Input error\n");
                    break;
                }
                switch (field) {
                    case 1:
                        sortObjectsByField(1, direction, compareText);
                        break;
                    case 2:
                        sortObjectsByField(2, direction, compareFloat);
                        break;
                    case 3:
                        sortObjectsByField(3, direction, compareInt);
                        break;
                    default:
                        printf("Input error\n");
                }
                break;
            case 7:
                printf("Choose diagram num (1 - double, 2 - int): ");
                scanf("%d", &field);
                if (field>2){
                    printf("Input error\n");
                    break;
                }
                printf("Choose diagram (1 - columnar, 2 - circular): ");
                scanf("%d", &chartType);
                switch (chartType) {
                    case 1:
                        drawBarChart(field);
                        break;
                    case 2:
                        drawPieChart(field);
                        break;
                    default:
                        printf("Input error\n");
                }
                break;
            case 8:
                exit(0);
            default:
                printf("Input error\n");
        }
    }
    return 0;
}
