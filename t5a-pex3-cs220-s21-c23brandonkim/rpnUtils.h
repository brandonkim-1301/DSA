/** rpnUtils.c
 * ===========================================================
 * Name: Brandon Kim, 19 FEB 2021
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Reverse polish notation utilities library
 * ===========================================================
 */

#ifndef RPNUTILS_H
#define RPNUTILS_H
#define _CRT_SECURE_NO_WARNINGS  // Hide "unsafe, deprecated" warnings, must be at the top

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "queueAsLinkedList.h"
#include "stackAsLinkedList.h"

#define MAXCHAR 100 // Maximum number of characters for the user's input


// prototypes for utility functions

/** promptForInput()
 * @brief - asks for and stores the user's input 
 * @pre    - input string is empty
 * @post   - input string is stored with the user's RPN expression 
 */
void promptForInput(char* input);

/** queueRPNExpression()
 * @brief  - Inserts valid inputs into a queue for the RPN calculator
 * @param queue - a pointer to the queue for the RPN expression
 * @param input - a string that has the user's input for the RPN expression
 * @return - 1 on success, or 0 on failure
 * @pre    - queue is empty
 * @post   - queue is filled with valid operands and operators  
 */
int queueRPNExpression(QueueAsLinkedList* queue, char* input);

/** solveRPNExpression()
 * @brief  - Dequeues queue into a stack and solves the RPN expression
 * @param queue - a pointer to the queue for the RPN expression
 * @param stack - a pointer to the stack for the RPN calculations
 * @return - solution to three decimal places on success
 * @pre    - queue has the RPN expression, stack is empty
 * @post   - stack only holds the answer to the RPN expression  
 */
double solveRPNExpression(QueueAsLinkedList* queue, StackAsLinkedList* stack);

#endif  // RPNUTILS_H
