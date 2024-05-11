#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
//Zakharow Timofey 123-mm
Object* objects = NULL;
int objectCount = 0;

void display_menu() {
    printf("|---------------------|\n");
    printf("| 1. Show database    |\n");
    printf("| 2. Add object       |\n");
    printf("| 3. Delete from file |\n");
    printf("| 4. Save to file     |\n");
    printf("| 5. Read from file   |\n");
    printf("| 6. Sort objects     |\n");
    printf("| 7. Show diagram     |\n");
    printf("| 8. Exit             |\n");
    printf("|---------------------|\n");
}

void print_table() {
    for (int i = 0; i < objectCount; i++) {
        printf("Element ID %d: | Text: %s | Double num: %f | Int num: %d\n", i, objects[i].text, objects[i].floatValue, objects[i].intValue);
    }
}
