/** pex0.c
* ===========================================================
* Name: Brandon Kim, 09 JAN 2021
* Section: T5A
* Project: C Proficiency
* Purpose: This project assesses basic skills in the C 
*           programming language, which were taught in CS210. 
* Documentation: NONE
* =========================================================== */ 

#include "pex0functs.h"

int main(char *filename, int rows, int columns) {
    char userInput[80];
    printf("Enter a sentence: \n");
    fgets(userInput, 80, stdin);
    parseIt(userInput);
    printf(userInput);
    printf("\n");

    char userInput2[80];
    printf("Enter another sentence: \n");
    fgets(userInput2, 80, stdin);
    char *modifiedInput = modifyIt(userInput2);
    printf(modifiedInput);
    printf("\n");

    StudentRecType newStudent;
    getInfo(&newStudent);
    printf("%s is %d years old.\n", newStudent.name, newStudent.age);

    int **twoDimArray = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; ++i) {
        twoDimArray[i] = (int*)malloc(sizeof(int) * columns);
    }
    fillIt(twoDimArray, rows, columns);
    dumpIt(twoDimArray, rows, columns, filename);
    for(int i = 0; i < rows; ++i) {
        free(twoDimArray[i]);
    }
    free(twoDimArray);

    printf("This assignment took 180 minutes");

    char c;
    scanf(" %c", &c);
    return 0;
}