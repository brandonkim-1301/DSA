/** unitTests.c
 * ===========================================================
 * Name: Brandon Kim, 19 FEB 2021
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Unit Tests for List ADTs.
 * ===========================================================
 */

#include "unitTests.h"

/** runAllListAsLinkedListTests()
 * @brief  - performs unit tests for list ADT as linked list '
 * @return - 1 if all tests are passed
 * @pre    - nothing
 * @post   - displays if all tests have been passed
 */
int runAllListAsLinkedListTests() {
    // Create and assert that list is made
    LinkedList* list;
    list = createLinkedList();
    assert(list != NULL);

    // Find the length of the empty list and asserts that it is zero
    int lengthOfList = lengthOfLinkedList(list);
    assert(lengthOfList == 0);

    // Append and assert that first node has correct number
    double* itemPtr = malloc(sizeof(double));   
    *itemPtr = 7.0;
    appendElementLinkedList(list, itemPtr, REAL_NUMBER);
    printLinkedList(list);
    ElementType theType;
    double* itemReturn = getElementLinkedList(list, 0, &theType);
    assert(theType == REAL_NUMBER);
    assert(*itemReturn == 7.0);
    assert(list->numberOfElements == 1);
   
    // Append and assert that second node has correct number
    double* itemPtr1 = malloc(sizeof(double));   
    *itemPtr1 = 14.0;
    appendElementLinkedList(list, itemPtr1, REAL_NUMBER);
    printLinkedList(list);
    itemReturn = getElementLinkedList(list, 1, &theType);
    assert(theType == REAL_NUMBER);
    assert(*itemReturn == 14.0);
    assert(list->numberOfElements == 2);

    // Append and assert that third node has correct operator
    char* itemPtrOp = malloc(sizeof(char));
    *itemPtrOp = '+';
    appendElementLinkedList(list, itemPtrOp, MATH_OPERATOR);
    printLinkedList(list);
    char* itemReturnOp = getElementLinkedList(list, 2, &theType);
    assert(theType == MATH_OPERATOR);
    assert(*itemReturnOp == '+');
    assert(list->numberOfElements == 3);

    // Append and assert that fourth node has correct opeator
    char* itemPtrOp1 = malloc(sizeof(char));
    *itemPtrOp1 = '*';
    appendElementLinkedList(list, itemPtrOp1, MATH_OPERATOR);
    printLinkedList(list);
    itemReturnOp = getElementLinkedList(list, 3, &theType);
    assert(theType == MATH_OPERATOR);
    assert(*itemReturnOp == '*');
    assert(list->numberOfElements == 4);

    // Insert new number into the first node and assert that first node has correct number
    double* itemPtr2 = malloc(sizeof(double));   
    *itemPtr2 = 8.0;
    insertElementLinkedList(list, 0, itemPtr2, REAL_NUMBER);
    printLinkedList(list);
    itemReturn = getElementLinkedList(list, 0, &theType);
    assert(theType == REAL_NUMBER);
    assert(*itemReturn == 8.0);
    assert(list->numberOfElements == 5);

    // Insert new number into the third node and assert that third node has correct number
    double* itemPtr3 = malloc(sizeof(double));   
    *itemPtr3 = 27.0;
    insertElementLinkedList(list, 2, itemPtr3, REAL_NUMBER);
    printLinkedList(list);
    itemReturn = getElementLinkedList(list, 2, &theType);
    assert(theType == REAL_NUMBER);
    assert(*itemReturn == 27.0);
    assert(list->numberOfElements == 6);

    // Insert new operator into the last node and assert that last node has correct operator
    char* itemPtrOp2 = malloc(sizeof(char));
    *itemPtrOp2 = '-';
    insertElementLinkedList(list, 6, itemPtrOp2, MATH_OPERATOR);
    printLinkedList(list);
    itemReturnOp = getElementLinkedList(list, 6, &theType);
    assert(theType == MATH_OPERATOR);
    assert(*itemReturnOp == '-');
    assert(list->numberOfElements == 7);

    // Change number in first node and assert that first node has new correct number
    double* itemPtr4 = malloc(sizeof(double));   
    *itemPtr4 = 100.0;
    changeElementLinkedList(list, 0, itemPtr4, REAL_NUMBER);
    printLinkedList(list);
    itemReturn = getElementLinkedList(list, 0, &theType);
    assert(theType == REAL_NUMBER);
    assert(*itemReturn == 100.0);
    assert(list->numberOfElements == 7);

    // Change number in third node and assert that third node has new correct number
    double* itemPtr5 = malloc(sizeof(double));   
    *itemPtr5 = 200.0;
    changeElementLinkedList(list, 2, itemPtr5, REAL_NUMBER);
    printLinkedList(list);
    itemReturn = getElementLinkedList(list, 2, &theType);
    assert(theType == REAL_NUMBER);
    assert(*itemReturn == 200.0);
    assert(list->numberOfElements == 7);

    // Change operator in last node and assert that last node has new correct operator
    char* itemPtrOp3 = malloc(sizeof(char));
    *itemPtrOp3 = '^';
    changeElementLinkedList(list, 6, itemPtrOp3, MATH_OPERATOR);
    printLinkedList(list);
    itemReturnOp = getElementLinkedList(list, 6, &theType);
    assert(theType == MATH_OPERATOR);
    assert(*itemReturnOp == '^');
    assert(list->numberOfElements == 7);

    // Delete first node and assert that the new first node was the old second node
    deleteElementLinkedList(list, 0);
    printLinkedList(list);
    itemReturn = getElementLinkedList(list, 0, &theType);
    assert(theType == REAL_NUMBER);
    assert(*itemReturn == 7.0);
    assert(list->numberOfElements == 6);

    // Delete third node and assert that the new third node was the old fourth node
    deleteElementLinkedList(list, 2);
    printLinkedList(list);
    itemReturnOp = getElementLinkedList(list, 2, &theType);
    assert(theType == MATH_OPERATOR);
    assert(*itemReturnOp == '+');
    assert(list->numberOfElements == 5);

    // Delete last node and assert that the new last node was the old second-to-last node
    deleteElementLinkedList(list, 4);
    printLinkedList(list);
    itemReturnOp = getElementLinkedList(list, 3, &theType);
    assert(theType == MATH_OPERATOR);
    assert(*itemReturnOp == '*');
    assert(list->numberOfElements == 4);

    // Find the length of a list with elements and assert that it is right length
    lengthOfList = lengthOfLinkedList(list);
    assert(lengthOfList == 4);

    // Clear the list and assert that the list is empty
    deleteLinkedList(list);
    printLinkedList(list);
    assert(list->head == list->tail);
    assert(list->numberOfElements == 0);

    // Print 'Passed All Tests!' if all tests are passed
    printf("\n\nPassed All Tests!\n\n");
    return 1;
}