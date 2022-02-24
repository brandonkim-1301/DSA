/** pex2sorts.c
 * ===========================================================
 * Name: Brandon Kim, 4 FEB 2021
 * Section: T5A
 * Project: Search Algorithms & Analysis
 * Purpose: This project implements selection, insertion, bubble,
 *          and Merge sort algorithms. Data sets are sorted in 
 *          descending order.
 * Documentation: None. 
 * ===========================================================
 */

#include "pex2sorts.h"

int main() {
    int numSize = 7;   // Size of the int array
    int *nums = (int*)malloc(sizeof(int) * numSize);

    srand((unsigned)(time(NULL)));

    fillArray(nums, numSize);
    selectionSort(nums, numSize);
    printArray(nums, numSize);

    fillArray(nums, numSize);
    insertionSort(nums, numSize);
    printArray(nums, numSize);

    fillArray(nums, numSize);
    bubbleSort(nums, numSize);
    printArray(nums, numSize);

    fillArray(nums, numSize);
    mergeSort(nums, numSize);
    printArray(nums, numSize);

    system("pause");
    return 0;
}

void fillArray(int array[], int N) {
    // This fills an array with random ints from 0 to 49
    for (int i = 0; i < N; i++) {
        array[i] = (int)rand() % 50;
    }
}

void printArray(int array[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void selectionSort(int array[], int N) {
    int indexLargest;
    int temp;
    for(int i = 0; i < N - 1; i++) {
        indexLargest = i;
        for(int j = i + 1; j < N; j++) {
            if(array[j] > array[indexLargest]) {
                indexLargest = j;
            }
        }
        temp = array[i];
        array[i] = array[indexLargest];
        array[indexLargest] = temp;
    }
}

void insertionSort(int array[], int N) {
    int temp;
    int j;
    for(int i = 0; i < N; i++) {
        j = i;
        while(j > 0 && array[j] > array[j - 1]) {
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
}

void bubbleSort(int array[], int N) {
    int temp;
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - i - 1; j++) {
            if(array[j] < array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void mergeSort(int array[], int N) {
    mergeSortingArray(array, 0, N - 1);
}

void merge(int array[], int lBound, int mid, int rBound) {
    int mergedSize = rBound - lBound + 1;
    int mergePos = 0;
    int leftPos = lBound;
    int rightPos = mid + 1;
    int *mergedArray = (int*)malloc(sizeof(int) * mergedSize);

    while(leftPos <= mid && rightPos <= rBound) {
        if(array[leftPos] >= array[rightPos]) {
            mergedArray[mergePos] = array[leftPos];
            leftPos++;
        } else {
            mergedArray[mergePos] = array[rightPos];
            rightPos++;
        }
        mergePos++;
    }

    while(leftPos <= mid) {
        mergedArray[mergePos] = array[leftPos];
        leftPos++;
        mergePos++;
    }

    while(rightPos <= rBound) {
        mergedArray[mergePos] = array[rightPos];
        rightPos++;
        mergePos++;
    }

    for(mergePos = 0; mergePos < mergedSize; mergePos++) {
        array[lBound + mergePos] = mergedArray[mergePos];
    }
}

void mergeSortingArray(int numbers[], int lBound, int rBound) {
    int mid = 0;

    if(lBound < rBound) {
        mid = (lBound + rBound) / 2;

        mergeSortingArray(numbers, lBound, mid);
        mergeSortingArray(numbers, mid + 1, rBound);

        merge(numbers, lBound, mid, rBound);
    }
}