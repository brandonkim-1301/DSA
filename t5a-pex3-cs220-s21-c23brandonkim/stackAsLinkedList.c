/** stackAsLinkedList.c
 * ===========================================================
 * Name: Brandon Kim, 19 FEB 2021
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Stack ADT library - LIFO
 * ===========================================================
 */
#include "stackAsLinkedList.h"

/** stackPush()
 * @brief - puts an element onto the top of the stack
 * @param element - ptr to thethe value to push onto the stack
 * @param type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre   - 1. void* pointing to dynamically allocated element
 *          2. stack before element added
 * @post  - stack one element taller
 */
void stackPush(StackAsLinkedList* stack, void* element, ElementType type) {
    // Inserts new element to stack, with head being the top
    insertElementLinkedList(stack, 0, element, type);
}


/** stackPop()
 * @brief  - pops an element off the stack
 * @param  stack - a ptr to the stack structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr to the top of the stack on success, NULL on failure
 * @pre    - stack before top element removed; type to be modified unchanged
 * @post   - stack one element element shorter; node type updated; ptr to element returned
 */
void* stackPop(StackAsLinkedList* stack, ElementType* type) {
    // Pops from top of the stack, with head being the top
    void* element = getElementLinkedList(stack, 0, type);
    deleteElementLinkedList(stack, 0);
    return element;
}

/** stackIsEmpty()
 * @brief  - determines if the stack is empty
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is empty or false
 * @pre    - stack unmodified
 * @post   - stack unmodified; and empty status returned
 */
bool stackIsEmpty(StackAsLinkedList* stack) {
    return stackSize(stack) == 0;
}

/** stackIsFull()
 * @brief - determines if the stack is full
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is full or false
 * @pre    - stack unmodified
 * @post   - stack unmodified; always returns false
 */
bool stackIsFull(StackAsLinkedList* stack) {
    // References formal parameter of function, but always returns false
    return stack && 0;
}

/** stackInit()
 * @brief  - initializes the stack structure
 * @return - pointer to stack
 * @pre    - nothing
 * @post   - new empty stack returned
 */
StackAsLinkedList* stackInit() {
    return createLinkedList();
}

/** deleteStack(()
 * @brief  - deletes stack, freeing all memory used
 * @param stack - a ptr to the stack structure
 * @pre    - unmodified stack
 * @post   - the stack is erased
 */
void deleteStack(StackAsLinkedList* stack) {
    deleteLinkedList(stack);
}

/** stackPeek()
 * @brief  - returns the item on the top of the
 *           stack but doesn't remove it
 * @param stack - a ptr to the stack structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr the item on the top of the stack; NULL on failure
 * @pre    - stack unmodified; type to be updated unchanged
 * @post   - stack unmodified; ptr to top element returned;
 *           type updated with the type of element being returned
 */
void* stackPeek(StackAsLinkedList* stack, ElementType* type) {
    // Peeks at element at the top of the stack, with the head being the top
    return getElementLinkedList(stack, 0, type);
}

/** stackSize()
 * @brief  - determines the size of the stack
 * @param stack - a ptr to the stack structure
 * @return - number of items in the stack
 * @pre    - stack unmodified
 * @post   - stack unmodified; size of stack returned
 */
int stackSize(StackAsLinkedList* stack) {
    return lengthOfLinkedList(stack);
}

/** stackPrint()
 * @brief  - outputs the stack to the console
 * @param stack - the stack structure
 * @pre    - stack unmodified
 * @post   - stack unmodified; stack elements printed
 */
void stackPrint(StackAsLinkedList* stack) {
    // Prints all elements from the top of the stack, with the head being the top
    printLinkedList(stack);
}