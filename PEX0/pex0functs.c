/** pex0functs.c
* ===========================================================
* Name: Brandon Kim, 09 JAN 2021
* Section: T5A
* Project: C Proficiency
* Purpose: This project assesses basic skills in the C 
*           programming language, which were taught in CS210. 
* =========================================================== */ 

#include "pex0functs.h"

void parseIt(char *inputStr) {
    int inputLen = strlen(inputStr);
    for(int i = 0; i < inputLen; ++i) {
        if(inputStr[i] == ' ') {
            inputStr[i] = '-';
        } else if(inputStr[i] == 't' || inputStr[i] == 'T') {
            inputStr[i] = ' ';
        }
    }
}

char* modifyIt(char *inputStr) {
    int inputLen = strlen(inputStr);
    char *modStr = (char*)malloc(sizeof(char) * inputLen);
    strcpy(modStr, "start->");
    strcat(modStr, inputStr);
    strcat(modStr, "<-end");
    return modStr;
}

void getInfo(StudentRecType *inputStud) {
    printf("Enter a name: \n");
    fgets(inputStud->name, 64, stdin);
    printf("Enter an age: \n");
    scanf("%d", &inputStud->age);
}

void fillIt(int **inputArray, int inputRows, int inputCols) {
    for(int i = 0; i < inputRows; ++i) {
        for(int j = 0; j < inputCols; ++j) {
            inputArray[i][j] = rand() % 100 + 1;
        }
    }
}

void dumpIt(int **inputArray, int inputRows, int inputCols, char *filename) {
    FILE *out = fopen(filename, "w+");
    if(out == NULL) {
        printf("%s was not found...", filename);
        exit(0);
    }
    for(int i = 0; i < inputRows; ++i) {
        for(int j = 0; j < inputCols; ++j) {
            fprintf(out, "%d ", inputArray[i][j]);
        }
        printf("\n");
    }
}