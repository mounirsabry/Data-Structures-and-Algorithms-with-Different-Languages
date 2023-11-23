#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Header Files/Algorithms.h"

int main()
{
    //Seeding rand with time to prevent generating the same sequence every run.
    srand(time(NULL));
    //The default seed for rand is 1, therefore it generates the same sequence by default.

    int length = 15;
    int startLimit = 5;
    int endLimit = 50;

    int *pNumbers = (int *) malloc(length * sizeof(int));
    float *pFloats = (float *) malloc (length * sizeof(float));
    double *pDoubles = (double *) malloc (length * sizeof(double));
    puts("-------------------------------------------------------");
    puts("Fill Random.");
    puts("------------");
    fillRandomInt(pNumbers, length);
    fillRandomFloat(pFloats, length);
    fillRandomDouble(pDoubles, length);

    printf("pNumbers :");
    printIntList(pNumbers, length);

    printf("pFloats :");
    printFloatList(pFloats, length);

    printf("pDoubles :");
    printDoubleList(pDoubles, length);
    puts("-------------------------------------------------------");
    printf("Fill Random with Limits (%d, %d).\n", startLimit, endLimit);
    puts("--------------------------------");
    fillRandomIntLimit(pNumbers, length, startLimit, endLimit);
    fillRandomFloatLimit(pFloats, length, startLimit, endLimit);
    fillRandomDoubleLimit(pDoubles, length, startLimit, endLimit);

    printf("pNumbers :");
    printIntList(pNumbers, length);

    printf("pFloats :");
    printFloatList(pFloats, length);

    printf("pDoubles :");
    printDoubleList(pDoubles, length);

    //Free after fill.
    free(pNumbers);
    free(pFloats);
    free(pDoubles);
    
    puts("-------------------------------------------------------");
    puts("Sorting Algorithm.");
    puts("------------------");
    length = 10;
    startLimit = 1;
    endLimit = 30;
    pNumbers = (int *) malloc(length * sizeof(int));
    int *pNumbersCopy = NULL;

    fillRandomIntLimit(pNumbers, length, startLimit, endLimit);
    printf("The List Unsorted          :");
    printIntList(pNumbers, length);

    pNumbersCopy = deepCopyListInt(pNumbers, length);
    bubbleSort(pNumbersCopy, length);
    printf("Bubble Sort Sorted List    :");
    printIntList(pNumbersCopy, length);
    free(pNumbersCopy);
    pNumbersCopy = NULL;

    pNumbersCopy = deepCopyListInt(pNumbers, length);
    insertionSort(pNumbersCopy, length);
    printf("Insertion Sort Sorted List :");
    printIntList(pNumbersCopy, length);
    free(pNumbersCopy);
    pNumbersCopy = NULL;

    pNumbersCopy = deepCopyListInt(pNumbers, length);
    selectionSort(pNumbersCopy, length);
    printf("Selection Sort Sorted List :");
    printIntList(pNumbersCopy, length);
    free(pNumbersCopy);
    pNumbersCopy = NULL;

    puts("-------------------------------------------------------");
    puts("Search Algorithms.");
    puts("------------------");
    length = 12;
    startLimit = 1;
    endLimit = 30;
    int key;
    pNumbers = (int *) malloc (length * sizeof(int));
    fillRandomIntLimit(pNumbers, length, startLimit, endLimit);
    key = startLimit + rand() % (endLimit - startLimit + 1);

    printf("The List :");
    printIntList(pNumbers, length);
    printf("The Key :%d\n", key);
    printf("The list and the key are auto generated with limits (%d, %d).\n\n", startLimit, endLimit);

    puts("Does the list contains the key?");

    int sequentialSearchKeyIndex = sequentialSearchUnsorted(pNumbers, length, key);
    printf("The Sequential Search Unsorted Says \"");
    if (sequentialSearchKeyIndex == -1)
    {
        printf("No, The key does not exist in the list");
    }
    else
    {
        printf("Yes, it is at index %d (counting from zero)", sequentialSearchKeyIndex);
    }
    printf("\".\n");

    sequentialSearchKeyIndex = sequentialSearchSorted(pNumbers, length, key);
    printf("The Sequential Search Sorted Says \"");
    if (sequentialSearchKeyIndex == -1)
    {
        printf("No, The key does not exist in the list");
    }
    else
    {
        printf("Yes, it is at index %d (counting from zero)", sequentialSearchKeyIndex);
    }
    printf("\".\n");

    int binarySearchKeyIndex = binarySearchRecV1(pNumbers, length, key);
    printf("The Binary Search V1 Says \"");
    if (binarySearchKeyIndex == -1)
    {
        printf("No, The key does not exist in the list");
    }
    else
    {
        printf("Yes, it is at index %d (counting from zero)", binarySearchKeyIndex);
    }
    printf("\".\n");

    binarySearchKeyIndex = binarySearchRecV2(pNumbers, length, key);
    printf("The Binary Search V2 Says \"");
    if (binarySearchKeyIndex == -1)
    {
        printf("No, The key does not exist in the list");
    }
    else
    {
        printf("Yes, it is at index %d (counting from zero)", binarySearchKeyIndex);
    }
    printf("\".\n");

    puts("");
    puts("Let's Sort the List and Test Again.");
    insertionSort(pNumbers, length);
    printf("The List Sorted :");
    printIntList(pNumbers, length);
    printf("The key :%d", key);

    puts("");
    puts("Does the list contains the key?");

    sequentialSearchKeyIndex = sequentialSearchUnsorted(pNumbers, length, key);
    printf("The Sequential Search Unsorted Says \"");
    if (sequentialSearchKeyIndex == -1)
    {
        printf("No, The key does not exist in the list");
    }
    else
    {
        printf("Yes, it is at index %d (counting from zero)", sequentialSearchKeyIndex);
    }
    printf("\".\n");

    sequentialSearchKeyIndex = sequentialSearchSorted(pNumbers, length, key);
    printf("The Sequential Search Sorted Says \"");
    if (sequentialSearchKeyIndex == -1)
    {
        printf("No, The key does not exist in the list");
    }
    else
    {
        printf("Yes, it is at index %d (counting from zero)", sequentialSearchKeyIndex);
    }
    printf("\".\n");

    binarySearchKeyIndex = binarySearchRecV1(pNumbers, length, key);
    printf("The Binary Search V1 Says \"");
    if (binarySearchKeyIndex == -1)
    {
        printf("No, The key does not exist in the list");
    }
    else
    {
        printf("Yes, it is at index %d (counting from zero)", binarySearchKeyIndex);
    }
    printf("\".\n");

    binarySearchKeyIndex = binarySearchRecV2(pNumbers, length, key);
    printf("The Binary Search V2 Says \"");
    if (binarySearchKeyIndex == -1)
    {
        printf("No, The key does not exist in the list");
    }
    else
    {
        printf("Yes, it is at index %d (counting from zero)", binarySearchKeyIndex);
    }
    printf("\".\n");

    puts("");
    printf("As you can see, the binary search requires the list to be sorted");
    printf(", while the sequential search does not (depending on the implementation).\n");
    printf("If the binary search found the element in an unsorted list, it does mean that the search algorithm");
    printf(" got lucky and found the element in the middle of the list\nor by luck by searching one side so that the element");
    printf(" became the middle element in the sub list.\n");
    printf("Unsorted Sequential Search may be inefficient, but it works on Unsorted and Sorted lists.\n");
    printf("Sorted Sequential Search cuts early if he finds an element that is bigger than the key, this makes it more efficient");
    printf(" in case of Sorted list, because it does not need to search the rest of the list.\n");
    printf("However, if you gave the Sorted Sequential Search an Unsorted list, it may cut early even if the key exists in the list.\n");

    puts("");
    printf("In case that the key appeared more than once in the list\nSince the Sequential search loops on the list elemenet");
    printf(" by element from the start,\nSequential search guarantees finding the first instance of the key in the list.\n");
    printf("The Binary search on the other hand does not guarantees that, it will get the instance that closet to its path of searching ");
    printf("It may be the first instance, and it may be not.\n");
    printf("");

    free(pNumbers);
    puts("-------------------------------------------------------");
    return 0;
}