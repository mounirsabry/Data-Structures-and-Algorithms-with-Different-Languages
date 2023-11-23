#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Header Files/Algorithms.h"

void printIntList(int *list, int length)
{
    if (length == 0 || list == NULL)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
    puts("");
    return;
}
void printFloatList(float *list, int length)
{
    if (length == 0 || list == NULL)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        printf("%.2f ", list[i]);
    }
    puts("");
    return;
}
void printDoubleList(double *list, int length)
{
    if (length == 0 || list == NULL)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        printf("%.2f ", list[i]);
    }
    puts("");
    return;
}
//Fill a List with Random Numbers.
void fillRandomInt(int *list, int length)
{
    if (length == 0 || list == NULL)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        list[i] = rand();
    }
    return;
}
void fillRandomIntLimit(int *list, int length, int start, int end)
{
    if (length == 0 || list == NULL)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        list[i] = (rand() % (end - start + 1)) + start;
    }
    return;
}
void fillRandomFloat(float *list, int length)
{
    if (length == 0 || list == NULL)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        list[i] = rand() + (float)rand() / RAND_MAX;
    }
    return;
}
void fillRandomFloatLimit(float *list, int length, int start, int end)
{
    if (length == 0 || list == NULL)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        list[i] = (start + rand() % (end - start + 1)) + (float)rand() / RAND_MAX;
    }
    return;
}
void fillRandomDouble(double *list, int length)
{
    if (length == 0 || list == NULL)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        list[i] = rand() + (double)rand() / RAND_MAX;
    }
    return;
}
void fillRandomDoubleLimit(double *list, int length, int start, int end)
{
    if (length == 0 || list == NULL)
    {
        return;
    }
    for (int i = 0; i < length; i++)
    {
        list[i] = (start + rand() % (end - start + 1)) + (double)rand() / RAND_MAX;
    }
    return;
}
//Deep Copy a list into another list.
int *deepCopyListInt(int *list, int length)
{
    if (list == NULL || length == 0)
    {
        return NULL;
    }
    int *newList = (int *) malloc (length * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        newList[i] = list[i];
    }
    return newList;
}
float *deepCopyListFloat(float *list, int length)
{
if (list == NULL || length == 0)
    {
        return NULL;
    }
    float *newList = (float *) malloc (length * sizeof(float));
    for (int i = 0; i < length; i++)
    {
        newList[i] = list[i];
    }
    return newList;
}
double *deepCopyListDouble(double *list, int length)
{
if (list == NULL || length == 0)
    {
        return NULL;
    }
    double *newList = (double *) malloc (length * sizeof(double));
    for (int i = 0; i < length; i++)
    {
        newList[i] = list[i];
    }
    return newList;
}
//Search Algorithms.
int sequentialSearchUnsorted(int *list, int length, int key)
{
    if (length == 0 || list == NULL)
    {
        return -1;
    }
    for (int i = 0; i < length; i++)
    {
        if (list[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int sequentialSearchSorted(int *list, int length, int key)
{
    if (length == 0 || list == NULL)
    {
        return -1;
    }
    for (int i = 0; i < length; i++)
    {
        if (list[i] == key)
        {
            return i;
        }
        if (list[i] > key)
        {
            return -1;
        }
    }
    return -1;
}
int binarySearchRecV1(int *list, int length, int key)
{
    if (list == NULL || length == 0)
    {
        return -1;
    }
    if (length == 1)
    {
        if (list[0] == key)
        {
            return 0;
        }
        return -1;
    }
    int midIndex = length / 2;
    int maxIndex = length - 1;
    int searchResult = -1;
    if (list[midIndex] == key)
    {
        return midIndex;
    }
    else if (key < list[midIndex] && midIndex != 0)
    {
        searchResult = binarySearchRecV1(&list[0], length / 2, key);
        if (searchResult != -1)
        {
            return searchResult;
        }
    }
    else if (key > list[midIndex] && midIndex != maxIndex)
    {
        searchResult = binarySearchRecV1(&list[midIndex + 1], ceil((float)length / 2) - 1, key);
        if (searchResult != -1)
        {
            return midIndex + 1 + searchResult;
        }
    }
    return -1;
}
int binarySearchRecV2(int *list, int length, int key)
{
    if (list == NULL || length == 0)
    {
        return -1;
    }
    if (length == 1)
    {
        if(list[0] == key)
        {
            return 0;
        }
        return -1;
    }
    int midIndex = length / 2;
    int minIndex = 0;
    int maxIndex = length - 1;
    if (list[midIndex] == key)
    {
        return midIndex;
    }
    else if (key < list[midIndex] && midIndex != minIndex)
    {
        return search(list, minIndex, midIndex - 1, key);
    }
    else if (key > list[midIndex] && midIndex != maxIndex)
    {
        return search(list, midIndex + 1, maxIndex, key);
    }
}
int search(int *list, int minIndex, int maxIndex, int key)
{
    if (minIndex == maxIndex)
    {
        if (list[minIndex] == key)
        {
            return minIndex;
        }
        return -1;
    }
    int midIndex = ceil((float)(minIndex + maxIndex) / 2);
    if (list[midIndex] == key)
    {
        return midIndex;
    }
    else if (key < list[midIndex] && midIndex != minIndex)
    {
        return search(list, minIndex, midIndex -1, key);
    }
    else if (key > list[midIndex] && midIndex != maxIndex)
    {
        return search(list, midIndex + 1, maxIndex, key);
    }
    return -1;
}
int binarySearchIt(int *list, int length, int key)
{
    puts("The function is not implemented yet.");
    return -1;
}
//Sorting Algorithms.
void bubbleSort(int *list, int length)
{
    if (list == NULL || length == 0)
    {
        return;
    }
    int sorted = 0;
    int temp = 0;
    while (!sorted)
    {
        sorted = 1;
        for (int i = 0; i < length - 1; i++)
        {
            if (list[i] > list[i + 1])
            {
                temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                sorted = 0;
            }
        }
    }
    return;
}
void insertionSort(int *list, int length)
{
    if (list == NULL || length == 0)
    {
        return;
    }
    int holeIndex, temp;
    for (int i = 1; i < length; i++)
    {
        holeIndex = i;
        while (list[holeIndex - 1] > list[holeIndex] && (holeIndex - 1) >= 0)
        {
            temp = list[holeIndex];
            list[holeIndex] = list[holeIndex - 1];
            list[holeIndex - 1] = temp;
            holeIndex -= 1;
        }
    }
    return;
}
void selectionSort(int *list, int length)
{
    if (list == NULL || length == 0)
    {
        return;
    }
    int smallestIndex, temp;
    for (int i = 0; i < length - 1; i++)
    {
        smallestIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (list[j] < list[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        if (smallestIndex != i)
        {
            temp = list[i];
            list[i] = list[smallestIndex];
            list[smallestIndex] = temp;
        }
    }
    return;
}