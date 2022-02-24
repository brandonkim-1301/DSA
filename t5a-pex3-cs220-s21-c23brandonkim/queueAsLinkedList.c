/** queueAsLinkedList.c
 * ===========================================================
 * Name: Brandon Kim, 19 FEB 2021
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Queue ADT library - FIFO
 * ===========================================================
 */

#include "queueAsLinkedList.h"

/** queueEnqueue()
 * @brief - puts an element onto the back of the queue
 * @param queue - a ptr to the queue structure
 * @param element - ptr to the value to add to the back of the queue
 * @param type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre   - 1. void* pointing to dynamically allocated element
 *          2. queue before element added
 * @post  - queue one element longer
 */
void queueEnqueue(QueueAsLinkedList* queue, void* element, ElementType type) {
    // Inserts element into the back of the queue, with the tail as the back
    appendElementLinkedList(queue, element, type);
}

/** queueDequeue()
 * @brief - removes an element from the front of the queue
 * @param queue - a ptr to the queue structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr to the value removed, type void*; NULL on failure
 * @pre   - queue before element removed from the front; type to be updated unmodified
 * @post  - queue one element shorter; node type updated; ptr to element returned
 */
void* queueDequeue(QueueAsLinkedList* queue, ElementType* type) {
    // Removes element from front of the queue, with the head as the front
    void* element = getElementLinkedList(queue, 0, type);
    deleteElementLinkedList(queue, 0);
    return element;
}

/** queueIsEmpty()
 * @brief  - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 * @pre    - queue unmodified
 * @post   - queue unmodified; and empty status returned
 */
bool queueIsEmpty(QueueAsLinkedList* queue) {
    return queueSize(queue) == 0;
}

/** queueIsFull()
 * @brief - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is full or false
 * @pre    - queue unmodified
 * @post   - queue unmodified; always returns false
 */
bool queueIsFull(QueueAsLinkedList* queue) {
    // References formal parameter of function, but always returns false
    return queue && 0;
}

/** queueInit()
 * @brief  - initializes the queue structure
 * @return - pointer to queue
 * @pre    - nothing
 * @post   - ptr to new empty queue returned
 */
QueueAsLinkedList* queueInit() {
    return createLinkedList();
}

/** deleteQueue()
 * @brief  - deletes queue, freeing all memory used
 * @param queue - a ptr to the queue structure
 * @pre    - unmodified queue
 * @post   - the queue is erased, all elements freed
 */
void deleteQueue(QueueAsLinkedList* queue) {
    deleteLinkedList(queue);
}

/** queuePeek()
 * @brief  - returns the item in the front of the
 *           queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr to the value at the front of the queue, type void*;
 *           NULL if queue is empty
 * @pre    - queue unmodified; type to be updated unmodified
 * @post   - queue unmodified; ptr to front element returned;
 *           type updated with the type of element being returned
 */
void* queuePeek(QueueAsLinkedList* queue, ElementType* type) {
    // Peeks at element at the front of the queue, with the head being the front
    return getElementLinkedList(queue, 0, type);
}

/** queueSize()
 * @brief  - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 * @pre    - queue unmodified
 * @post   - queue unmodified; size of queue returned
 */
int queueSize(QueueAsLinkedList* queue) {
    return lengthOfLinkedList(queue);
}

/** queuePrint()
 * @brief  - outputs the queue to the console
 * @param queue - the queue structure
 * @pre    - queue unmodified
 * @post   - queue unmodified; queue elements printed
 */
void queuePrint(QueueAsLinkedList* queue) {
    printLinkedList(queue);
}