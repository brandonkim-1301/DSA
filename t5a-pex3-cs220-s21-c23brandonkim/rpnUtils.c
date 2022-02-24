/** rpnUtils.c
 * ===========================================================
 * Name: Brandon Kim, 19 FEB 2021
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Reverse polish notation utilities library
 * ===========================================================
 */

#include "rpnUtils.h"

/** promptForInput()
 * @brief - asks for and stores the user's input 
 * @pre    - input string is empty
 * @post   - input string is stored with the user's RPN expression 
 */
void promptForInput(char* input) {
    // Prompts user for a RPN expression
    printf("Enter a RPN Expression: \n");
    fgets(input, MAXCHAR, stdin);
}

/** queueRPNExpression()
 * @brief  - Inserts valid inputs into a queue for the RPN calculator
 * @param queue - a pointer to the queue for the RPN calculator
 * @param input - a string that has the user's input for the RPN expression
 * @return - 1 on success, or 0 on failure
 * @pre    - queue is empty
 * @post   - queue is filled with valid operands and operators  
 */
int queueRPNExpression(QueueAsLinkedList* queue, char* input) {
    // Checks if there is an input 
    if(input == NULL) {
        return 0;
    }
    
    // Tokenizes string into individual ElementType elements and enqueues them
    char* delimiter = " ";  // Character separating each element of the input
    char* element = strtok(input, delimiter);   // Reads the first element of the input
    double ifRealNumber;
    char* validDigits = "0123456789";
    char leadingDecimal = '.';
    char signNegative = '-';

    while(element != NULL) {
        if (strchr(validDigits, *element) ||
        (strchr(element, leadingDecimal) != NULL && element[1] != '\0' && 
        strchr(validDigits, element[1])) || 
        (strchr(element, signNegative) != NULL && element[1] != '\0' && 
        strchr(validDigits, element[1]))) {
            //Queues the element, if it is a valid real number
            double* elementRealNum = malloc(sizeof(double));
            sscanf(element, "%lf", &ifRealNumber);
            *elementRealNum = ifRealNumber;
            queueEnqueue(queue, elementRealNum, REAL_NUMBER);
        } else {
             // Queues the element, if it is a valid operator
            switch(*element) {
                case('+'):
                    queueEnqueue(queue, element, MATH_OPERATOR);
                    break;
                case('-'):
                    queueEnqueue(queue, element, MATH_OPERATOR);
                    break;
                case('*'):
                    queueEnqueue(queue, element, MATH_OPERATOR);
                    break;
                case('/'):
                    queueEnqueue(queue, element, MATH_OPERATOR);
                    break;
                case('^'):
                    queueEnqueue(queue, element, MATH_OPERATOR);
                    break;
                default:
                    printf("invalid input: %s\n", element);
                    break;
            }
        }
        element = strtok(NULL, delimiter);
    }
    return 1;
}

/** solveRPNExpression()
 * @brief  - Dequeues queue into a stack and solves the RPN expression
 * @param queue - a pointer to the queue for the RPN expression
 * @param stack - a pointer to the stack for the RPN calculations
 * @return - solution to three decimal places on success, -0.0 if failure
 * @pre    - queue has the RPN expression, stack is empty
 * @post   - stack only holds the answer to the RPN expression  
 */
double solveRPNExpression(QueueAsLinkedList* queue, StackAsLinkedList* stack) {
    int errorPresent = 0;   // Stays low, unless an error is present in the input

    // Prints the tokenized queue, or the inputted RPN expression 
    printf("Tokenized Queue: ");
    queuePrint(queue);

    // Dequeues the queue until an operator
    void* element = NULL;
    ElementType curElementType;
    while(!queueIsEmpty(queue)) {
        element = queueDequeue(queue, &curElementType);

        // When a MATH_OPERATOR is dequeued, 
        //  the operator is performed on the top two elements of the stack
        if(curElementType == MATH_OPERATOR) {

            // Checks if there are enough numbers in the stack
            if(lengthOfLinkedList(stack) < 2) {
                printf("Not enough numbers to perform operation\n");
                errorPresent = 0;
            }

            // Prints the stack and the current operater
            char* operator = (char*)element;
            printf(" Operator: '%c' | Stack before operation: ", *operator);
            stackPrint(stack);

            // Pops the top two numbers in the stack
            double* numTop = (double*)stackPop(stack, &curElementType);
            double* numSecondTop = (double*)stackPop(stack, &curElementType);
            double* result = (double*)malloc(sizeof(double));

            // Performs the math operation using the top two numbers in the stack
            switch(*operator) {
                case('+'):
                    *result = *numSecondTop + *numTop;
                    stackPush(stack, result, REAL_NUMBER);
                    break;
                case('-'):
                    *result = *numSecondTop - *numTop;
                    stackPush(stack, result, REAL_NUMBER);
                    break;
                case('*'):
                    *result = *numSecondTop * *numTop;
                    stackPush(stack, result, REAL_NUMBER);
                    break;
                case('/'):
                    *result = *numSecondTop / *numTop;
                    stackPush(stack, result, REAL_NUMBER);
                    break;
                case('^'):
                    *result = pow(*numSecondTop, *numTop);
                    stackPush(stack, result, REAL_NUMBER);
                    break;
                default:
                    break;
            }
        } else {
            stackPush(stack, element, REAL_NUMBER);
        }
    }
    
    // Prints an error message if the input does not have enough operators
    if(lengthOfLinkedList(stack) > 1) {
        printf("Not enough operators\n");
        errorPresent = 1;
    }

    // Peeks the top of the stack and prints the answer to the RPN expression, if no errors present
    if(!errorPresent) {
        double* answer = (double*)stackPeek(stack, &curElementType);
        printf(" Answer: %.3lf\n", *answer);
        return *answer;
    }
    return -0.0;
}
