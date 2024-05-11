#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

// Struct to save objects
typedef struct {
    char text[50];
    float floatValue;
    int intValue;
} Object;

extern Object* objects;
extern int objectCount;

void display_menu();

void print_table();

#endif // BASE_H_INCLUDED
