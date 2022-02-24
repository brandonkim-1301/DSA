/** listAsLinkedList.c
 * ===========================================================
 * Name: Brandon Kim, 19 FEB 2021
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: List ADT as linked list
 * ===========================================================
 */

#include "listAsLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

/** createLinkedList()
 * @brief  - initializes the linked list structure
 * @return - pointer to linked list
 * @pre    - nothing
 * @post   - new empty linked list returned
 */
LinkedList* createLinkedList() {
    LinkedList* initNode = (LinkedList*)malloc(sizeof(LinkedList));

    // Uses a dummy node to simplify implementation of list
    Node* dummyNode = (Node*)malloc(sizeof(Node));
    initNode->head = dummyNode;
    initNode->tail = dummyNode;
    initNode->numberOfElements = 0;
    dummyNode->data = NULL;
    dummyNode->type = -1;
    dummyNode->next = NULL;
    // printf("Created new linked list.\n");
    return initNode;
}

/** deleteLinkedList(()
 * @brief  - deletes linked list, freeing all memory used
 * @param list - a ptr to the linked list structure
 * @pre    - unmodified linked list
 * @post   - the linked list is erased, all elements freed
 */
void deleteLinkedList(LinkedList* list) {
    // Deletes elements of linked list individually in reverse order
    for(int i = list->numberOfElements - 1; i >= 0; i--) {
        deleteElementLinkedList(list, i);
    }
    // printf("\nCleared linked list.\n");
}

/** appendElementLinkedList()
 * @brief - adds a new element to the end of the linked list
 * @param list - a ptr to the linked list structure
 * @param element - ptr to the value to append to the list
 * @param type - enum ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre   - 1. void* pointing to dynamically allocated element
 *          2. linked list before element added
 * @post  - modified linked list; node with pointer to element added
 */
void appendElementLinkedList(LinkedList* list, void* element, ElementType type) {
    insertElementLinkedList(list, list->numberOfElements, element, type);
    // printf("Appended element to linked list.\n");
 }

/** lengthOfLinkedList()
 * @brief  - returns the size of the linked list
 * @param list - a ptr to the linked structure
 * @return - number of items in the linked list
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; size of linked list returned
 */
int lengthOfLinkedList(LinkedList* list) {
    // printf("\nLength of linked list is %d.\n", list->numberOfElements);
    return list->numberOfElements;
}

/** printLinkedList()
 * @brief  - outputs the linked list to the console
 * @param list - the linked list structure
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; linked list elements printed
 */
void printLinkedList(LinkedList* list) {
    if(list->head->next == NULL) {
        printf("\nNo entries found in list...\n");
    } else {
        // printf("\nPrinting linked list...\n");
        Node* curNode = list->head->next;
        while(curNode != NULL) {
            // Prints the data based on its ElementType
            switch(curNode->type) {
                case REAL_NUMBER:
                    printf("%.3lf -> ", *(double*)curNode->data);
                    break;
                case MATH_OPERATOR:
                    printf("%c -> ", *(char*)curNode->data);
                    break;
                default:
                    printf("UNKNOWN ELEMENT TYPE");
                    break;
            }
            curNode = curNode->next;
        }
        printf("NULL\n");
    }
}

/** getElementLinkedList()
 * @brief  - retrieves element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value requested
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - value at 'position', NULL on failure
 * @pre    - unmodified linked list; unmodified element type to be updated
 * @post   - unmodified linked list; pointer to element at 'position' returned;
 *           type updated
 */
void* getElementLinkedList(LinkedList* list, int position, ElementType* type) {
    Node* curNode = list->head->next;
    int index = 0;
    while(curNode != NULL) {
        // Traverses through the list until the desired index is reached
        if(index == position) {
            switch(curNode->type) {
                case REAL_NUMBER:
                    *type = REAL_NUMBER;
                    return (double*)curNode->data;
                case MATH_OPERATOR:
                    *type = MATH_OPERATOR;
                    return (char*)curNode->data;
                default:
                    return NULL;
            }
        }
        curNode = curNode->next;
        index++;
    }
    return NULL;
}

/** deleteElementLinkedList()
 * @brief  - deletes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to delete
 * @pre    - unmodified linked list
 * @post   - modified linked list; node at 'position' removed;
 *           element of node being removed is freed;
 *           node removed is freed
 */
void deleteElementLinkedList(LinkedList* list, int position) {
    Node* curNode = list->head;
    Node* prevNode = NULL;
    int index = 0;
    while(curNode != NULL) {
        // Tracks the previous and current node
        prevNode = curNode;
        curNode = curNode->next;
        if(index == position) {
            // If the desired index is found, the previous node points to the next node or NULL
            if(index == list->numberOfElements - 1) {
                prevNode->next = NULL;
                list->tail = prevNode;
            } else {
                prevNode->next = curNode->next;
            }
            list->numberOfElements--;
            free(curNode);
            // printf("\nDeleted element in position %d.\n", index);
            return;
        }
        index++;
    }
    // printf("\nPosition not found.\n");
    return;
}

/** insertElementLinkedList()
 * @brief  - adds element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - ptr to value to be added
 * @param  type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre    - 1. void* pointing to dynamically allocated element
 *           2. linked list before element added
 * @post   - modified linked list; node with pointer to element added at 'position'
 */
void insertElementLinkedList(LinkedList* list, int position, void* element, ElementType type) {
    Node* curNode = list->head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    pointDataToElement(newNode, element, type);
    int index = 0;
    while(curNode != NULL) {
        if(index == position) {
            // If the desired index is found, the new node is inserted in the desired index
            newNode->next = curNode->next;
            curNode->next = newNode;
            if(curNode == list->tail){
                list->tail = newNode;
            }
            list->numberOfElements++;
            // printf("\nInserted element in position %d.\n", position);
            return;
        }
        curNode = curNode->next;
        index++;
    }
    // printf("\nPosition not found.\n");
    return;

}

/** changeElementLinkedList()
 * @brief  - changes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - ptr to new value
 * @param  type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre    - 1. void* pointing to dynamically allocated element
 *           2. linked list before element added
 * @post   - 1. modified linked list; node changed at 'position' with new pointer to a new element
 *           2. memory allocated to previous element freed
 */
void changeElementLinkedList(LinkedList* list, int position, void* newElement, ElementType type) {
    deleteElementLinkedList(list, position);
    insertElementLinkedList(list, position, newElement, type);
    // printf("\nChanged element in position %d.\n", position);
}

/** pointDataToElement()
 * @brief   - points to a new element and casts the ptr depending on ElementType
 * @param  node - a ptr to the node being manipulated
 * @param  element - ptr to value
 * @param  type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @return - 0 if ptr made to a REAL_NUMBER, 1 if ptr made to a MATH_OPERATOR,
 *              or -1 if ptr is not made
 * @pre    - 1. void* pointing to a dynamically allocated element
 *         - 2. ptr to data from node does not point to the element
 * @post   - ptr to data from node points to element
 */
int pointDataToElement(Node* node, void* element, ElementType type) {
    switch(type) {
        case REAL_NUMBER:
            (double*)node->data = element;
            node->type = type;
            return 0;
        case MATH_OPERATOR:
            (char*)node->data = element;
            node->type = type;
            return 1;
        default:
            return -1;
        }
}