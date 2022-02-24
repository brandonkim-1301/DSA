/** pex2sorts.h
 * ===========================================================
 * Name: Brandon Kim, 4 FEB 2021
 * Section: T5A
 * Project: Search Algorithms & Analysis
 * Purpose: This project implements selection, insertion, bubble,
 *          and Merge sort algorithms. Data sets are sorted in 
 *          descending order.
 * ===========================================================
 */

#ifndef PEX2SORTS_H
#define PEX2SORTS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** -------------------------------------------------------------------
 * @brief Fills an array with random values between 0 and 29
 * @param array - the array to fill
 * @param N - the size of the array to fill
 * @return none
 * @pre numbers has been allocated
 * @post array is filled with random numbers
 */
void fillArray(int array[], int N);

/** -------------------------------------------------------------------
 * @brief Prings an array
 * @param array - the array to print
 * @param N - the size of the array to print
 * @return none
 * @pre numbers has been allocated and initialized
 * @post array is printed nums is unmodified
 */
void printArray(int array[], int N);

/** -------------------------------------------------------------------
 * @brief Performs a selection sort on an array
 * @param array - the values to sort
 * @param N - the size of the array to sort
 * @return none
 * @pre array[] contains data, N contains the number of values
 * @post array[] is sorted in descending order
 */
void selectionSort(int array[], int N);

/** -------------------------------------------------------------------
 * @brief Performs an insertion sort on an array
 * @param array - the values to sort
 * @param N - the size of the array to sort
 * @return none
 * @pre array[] contains data, N contains the number of values
 * @post array[] is sorted in descending order
 */
void insertionSort(int array[], int N);

/** -------------------------------------------------------------------
 * @brief Performs a bubble sort on an array
 * @param array - the values to sort
 * @param N - the size of the array to sort
 * @return none
 * @pre array[] contains data, N contains the number of values
 * @post array[] is sorted in descending order
 */
void bubbleSort(int array[], int N);

/** -------------------------------------------------------------------
 * @brief Performs a merge sort on an array
 * @param array - the values to sort
 * @param N - the size of the array to sort
 * @return none
 * @pre array[] contains data, N contains the number of values
 * @post array[] is sorted in descending order
 */
void mergeSort(int array[], int N);

/** -------------------------------------------------------------------
 * @brief Merges two sorted sublists array[lBound..mid] and 
 * array[mid+1..rBound], into a single sorted list in 
 * array[lBound..rBound]
 * @param array - the array to sort
 * @param lBound - the lowest index of the first sublist
 * @param mid - the highest index of the first sublist
 * @param rBound - the highest index of the second sublist
 */
void merge(int array[], int lBound, int mid, int rBound);

/** -------------------------------------------------------------------
 * @brief Places values in ascending order array using merge sort
 * @param numbers - the numbers of an array to sort
 * @param lBound - the first index of the left-half of the array to sort
 * @param rBound - the last index of the right-half of the array to sort 
 * @return none
 * @pre numbers[] contains data, lBound is less than rBound
 * @post numbers[] is sorted in descending order
 */
void mergeSortingArray(int numbers[], int lBound, int rBound);

#endif  // PEX2SORTS_H