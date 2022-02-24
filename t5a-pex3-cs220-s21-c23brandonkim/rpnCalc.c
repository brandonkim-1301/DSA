/** rpnCalc.c
 * ===========================================================
 * Name: Brandon Kim, 19 FEB 2021
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Calculate answer given input in
 *          reverse polish notation
 * Documentation: I used tutorialspoint.com to understand how strtok() worked. This was necessary
 *                  to tokenize the user input string and store operators and operands as 
 *                  ElementType data.
 *                Dr. Bouvier explained how to tokenize negative and leading decimals and provided 
 *                  a demo file.
 * ===========================================================
 */

#define _CRT_SECURE_NO_WARNINGS  // Hides "unsafe, deprecated" warnings

#include "rpnUtils.h"

int main() {
    // Prompts the user for an RPN expression to compute
    char input[MAXCHAR];
    promptForInput(input);

    // Initializes the queue and stack used for the RPN calculations
    QueueAsLinkedList* queue = queueInit();
    StackAsLinkedList* stack = stackInit();

    // Computes the RPN expression
    int queueRPNResult;
    queueRPNResult = queueRPNExpression(queue, input);
    double solutionRPN;
    solutionRPN = solveRPNExpression(queue, stack);

    // Clear the queue and stacks after computation
    deleteQueue(queue);
    deleteStack(stack);

    return 0;  // Returns on success
}

