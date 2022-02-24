/** pex0functs.h
* ===========================================================
* Name: Brandon Kim, 09 JAN 2021
* Section: T5A
* Project: C Proficiency
* Purpose: This project assesses basic skills in the C 
*           programming language, which were taught in CS210. 
* =========================================================== */ 

#ifndef PEX0FUNCTS_H
#define PEX0FUNCTS_H 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct StudentRecType_struct {
    char name[64];
    int age;
} StudentRecType;

/**
* @brief Parses a sentence with specific syntax rules
* @param inputStr The sentence that is inputted by the user
* @return none
* @pre inputStr is a character array
* @post inputStr has dashes for spaces and spaces for "t" or "T"
*/
void parseIt(char*);

/**
* @brief Prepends and appends indicators to a sentence
* @param inputStr The sentence that is inputted by the user
* @return char pointer to a string
* @pre inputStr is a character array
* @post inputStr will have "start->" prepended and "<-end" appended to it
*/
char* modifyIt(char*);

/**
* @brief Collects student data, including name and age
* @param inputStud The pointer to the student that will hold the inputted name and age
* @return none
* @pre inputStud is a character array
* @post inputStud will have a string for its name and an integer for its age
*/

void getInfo(StudentRecType*);

/**
* @brief Populates a given two-dimensional array with random integers from 1 to 100
* @param inputArray The two-dimensional array to be populated
* @param inputRows The number of rows that the given two-dimensional array has
* @param inputCols The number of columns that the given two-dimensional array has
* @return none
* @pre inputArray is a two-dimensional array
* @post inputArray will be populated with random integers from 1 to 100
*/
void fillIt(int**, int, int);

/**
* @brief Prints integers from a two-dimensional array into a textfile
* @param inputArray The two-dimensional array to be populated
* @param inputRows The number of rows that the given two-dimensional array has
* @param inputCols The number of columns that the given two-dimensional array has
* @param filename The textfile that will contain integers from the two-dimensional array
* @return none
* @pre inputArray is a two-dimensional array
* @post filename will have integers from inputArray 
*/
void dumpIt(int**, int, int, char*);

#endif // PEX0FUNCTS_H
