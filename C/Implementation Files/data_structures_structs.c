#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Header Files/data_structures_structs.h"

// User Array.
typedef struct UserArray
{
    int *data;
    int capacity;
    int length;
} UserArray;
const int USER_ARRAY_DEFAULT_EMPTY_GROWTH_SIZE = 10;

UserArray *createUserArray(int initialCapacity)
{
    if (initialCapacity == 0) initialCapacity = 0;
    UserArray *array = (UserArray *) malloc (sizeof(UserArray));
    array->data = NULL;
    array->capacity = 0;
    growUserArray(array, initialCapacity);
    array->length = 0;
    return array;
};

void growUserArray(UserArray *array, int newCapacity)
{
    if (array == NULL || array->capacity < 0 || newCapacity == 0 || newCapacity <= array->capacity)
    {
        return;
    }
    if (array->capacity == 0)
    {
        array->data = (int *) malloc (newCapacity * sizeof(int));
        array->capacity = newCapacity;
    }
    else
    {
        int *newData = (int *) malloc (newCapacity * sizeof(int));
        for (int i = 0; i < array->capacity; i++)
        {
            newData[i] = array->data[i];
        }
        free(array->data);
        array->data = newData;
        array->capacity = newCapacity;
    }
    return;
}

int getValueUserArray(UserArray *array, int index)
{
    if (array == NULL || array->length < 0 || index < 0 || index >= array->length)
    {
        return INT_MIN;
    }
    return array->data[index];
}

int insertItemUserArray(UserArray *array, int index, int item)
{
    if (array == NULL || array->capacity < 0 || index < 0 || index > array->length)
    {
        return 0;
    }
    if (array->capacity == 0)
    {
        growUserArray(array, USER_ARRAY_DEFAULT_EMPTY_GROWTH_SIZE);
    }
    else if (array->length == array->capacity)
    {
        growUserArray(array, array->capacity * 2);
    }
    for (int i = array->length; i > index; i--)
    {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = item;
    array->length++;
    return 1;
}

int insertFirstUserArray(UserArray *array, int item)
{
    if (array == NULL || array->capacity < 0) return 0;
    return insertItemUserArray(array, 0, item);
}

int insertLastUserArray(UserArray *array, int item)
{
    if (array == NULL || array->capacity < 0) return 0;
    if (array->capacity == 0)
    {
        growUserArray(array, USER_ARRAY_DEFAULT_EMPTY_GROWTH_SIZE);
    }
    else if (array->length == array->capacity)
    {
        growUserArray(array, array->capacity * 2);
    }
    array->data[array->length] = item;
    array->length++;
    return 1;
}

int updateItemUserArray(UserArray *array, int index, int newValue)
{
    if (array == NULL || array->length <= 0 || index < 0 || index >= array->length)
    {
        return 0;
    }
    array->data[index] = newValue;
    return 1;
}

int deleteItemUserArray(UserArray *array, int index)
{
    if (array == NULL || array->length <= 0 || index < 0 || index >= array->length)
    {
        return 0;
    }
    for (int i = index; i < array->length - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->length--;
    return 1;
}

int deleteFirstUserArray(UserArray *array)
{
    if (array == NULL || array->length <= 0) return 0;
    return deleteItemUserArray(array, 0);
}

int deleteLastUserArray(UserArray *array)
{
    if (array == NULL || array->length <= 0)
    {
        return 0;
    }
    array->length--;
    return 1;
}

UserArray *deallocateUserArray(UserArray *array)
{
    if (array == NULL || array->capacity < 0) return NULL;
    free(array->data);
    array->data = NULL;
    array->capacity = array->length = -1;
    free(array);
    return NULL;
}

const int *getShallowListUserArray(UserArray *array)
{
    if (array == NULL || array->length < 0) return NULL;
    return array->data;
}

int *getDeepListUserArray(UserArray *array)
{
    if (array == NULL || array->length < 0) return NULL;
    int *copy = (int *) malloc (array->length * sizeof(int));
    for (int i = 0; i < array->length; i++)
    {
        copy[i] = array->data[i];
    }
    return copy;
}

int getCapacityUserArray(UserArray *array)
{
    if (array == NULL || array->capacity < 0) return -1;
    return array->capacity;
}

int getLengthUserArray(UserArray *array)
{
    if (array == NULL || array->length < 0) return -1;
    return array->length;
}

int findFirstUserArray(UserArray *array, int key)
{
    if (array == NULL || array->length <= 0)
    {
        return -1;
    }
    for (int i = 0; i < array->length; i++)
    {
        if (array->data[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void printUserArray(UserArray *array)
{
    printf("User Array Data :");
    if (array == NULL || array->length <= 0)
    {
        puts("Empty.");
        return;
    }
    int length = array->length;
    for (int i = 0; i < length; i++)
    {
        printf("%d", array->data[i]);
        if (i < length - 1) printf(" ");
    }
    puts(".");
}

// User Linked List.
typedef struct UserLinkedListNode UserLinkedListNode;
struct UserLinkedListNode
{
    int value;
    UserLinkedListNode *previous;
    UserLinkedListNode *next;
};

struct UserLinkedList
{
    UserLinkedListNode *head;
    UserLinkedListNode *tail;
    int length;
};

UserLinkedList *createUserLinkedList()
{
    UserLinkedList *list = (UserLinkedList *) malloc(sizeof(UserLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

UserLinkedListNode *navigateToNodeByIndex(UserLinkedList *list, int index)
{
    UserLinkedListNode *desiredNode = NULL; 
    int midIndex = list->length / 2;
    if (index < midIndex) // Start navigating from the head pointer.
    {

        int currentIndex = 0;
        desiredNode = list->head;
        while(currentIndex < index)
        {
            desiredNode = desiredNode->next;
            currentIndex++;
        }
    }
    else // Start navigating from the tail pointer.
    {
        int currentIndex = list->length - 1;
        desiredNode = list->tail;
        while(currentIndex > index)
        {
            desiredNode = desiredNode->previous;
            currentIndex--;
        }
    }
    return desiredNode;
}

UserLinkedListNode *navigateToNodeByValue(UserLinkedList *list, int value)
{
    UserLinkedListNode *desiredNode = list->head;
    while(desiredNode != list->tail)
    {
        if (desiredNode->value == value)
        {
            break;
        }
        desiredNode = desiredNode->next;
    }
    return desiredNode;
}

int getValueUserLinkedList(UserLinkedList *list, int index)
{
    if (list == NULL || list->length <= 0 || index < 0 || index >= list->length)
    {
        return INT_MIN;
    }
    return navigateToNodeByIndex(list, index)->value;
}

int insertItemUserLinkedList(UserLinkedList *list, int index, int item)
{
    if (list == NULL || list->length == -1 || index < 0 || index > list->length)
    {
        return 0;
    }
    if (index == list->length)
    {
        return insertLastUserLinkedList(list, item);
    }
    UserLinkedListNode *currentNode = navigateToNodeByIndex(list, index);
    UserLinkedListNode *newNode = (UserLinkedListNode *) malloc (sizeof(UserLinkedListNode));
    newNode->value = item;
    newNode->previous = currentNode->previous;
    newNode->next = currentNode;

    currentNode->previous->next = newNode;
    currentNode->previous = newNode;
    list->length++;
    return 1;
}

int insertFirstUserLinkedList(UserLinkedList *list, int item)
{
    if (list == NULL || list->length == -1)
    {
        return 0;
    }
    UserLinkedListNode *newNode = (UserLinkedListNode *) malloc(sizeof(UserLinkedListNode));
    newNode->value = item;
    newNode->previous = NULL;
    newNode->next = list->head;

    if (list->length == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->head->previous = newNode;
        list->head = newNode;
    }
    list->length++;
    return 1;
}

int insertLastUserLinkedList(UserLinkedList *list, int item)
{
    if (list == NULL || list->length == -1)
    {
        return 0;
    }
    UserLinkedListNode *newNode = (UserLinkedListNode *) malloc(sizeof(UserLinkedListNode));
    newNode->value = item;
    newNode->next = NULL;
    newNode->previous = list->tail;

    if (list->length == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->length++;
    return 1;
}

int updateItemUserLinkedList(UserLinkedList *list, int index, int newValue)
{
    if (list == NULL || list->length <= 0 || index < 0 || index >= list->length)
    {
        return 0;
    }
    UserLinkedListNode *indexNode = navigateToNodeByIndex(list, index);
    indexNode->value = newValue;
    return 1;
}

int deleteItemUserLinkedList(UserLinkedList *list, int index)
{
    if (list == NULL || list->length <= 0 || index < 0 || index >= list->length)
    {
        return 0;
    }
    UserLinkedListNode *indexNode = navigateToNodeByIndex(list, index);
    if (indexNode->previous != NULL)
    {   
        indexNode->previous->next = indexNode->next;
    }
    else // First Element in the List.
    {
        list->head = indexNode->next;
    }
    if (indexNode->next != NULL)
    {
        indexNode->next->previous = indexNode->previous;
    }
    else // Last Element in the list.
    {
        list->tail = indexNode->previous;
    }
    free(indexNode);
    list->length--;
    return 1;
}

int deleteFirstUserLinkedList(UserLinkedList *list)
{
    if (list == NULL || list->length <= 0)
    {
        return 0;
    }
    UserLinkedListNode *deletedNode = list->head;
    if (deletedNode->next != NULL)
    {
        deletedNode->next->previous = NULL;
        list->head = list->head->next;
    }
    else // Last Element in the List.
    {
        list->head = list->tail = NULL;
    }
    free(deletedNode);
    list->length--;
    return 1;
}

int deleteLastUserLinkedList(UserLinkedList *list)
{
    if (list == NULL || list->length <= 0)
    {
        return 0;
    }
    UserLinkedListNode *deletedNode = list->tail;
    if (deletedNode->previous != NULL)
    {
        deletedNode->previous->next = NULL;
        list->tail = deletedNode->previous;
    }
    else // Last Element in the List.
    {
        list->head = list->tail = NULL;
    }
    free(deletedNode);
    list->length--;
    return 1;
}

UserLinkedList *deallocateUserLinkedList(UserLinkedList *list)
{
    if (list == NULL || list->head == NULL || list->tail == NULL || list->length == -1)
    {
        return NULL;
    }
    UserLinkedListNode *currentNode = list->head;
    UserLinkedListNode *nextNode = NULL;
    while(currentNode != list->tail)
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    list->head = list->tail = NULL;
    list->length = -1;
    free(list);
    return NULL;
}

int *getDeepListUserLinkedList(UserLinkedList *list)
{
    if (list == NULL || list->length <= 0)
    {
        return NULL;
    }
    int length = list->length;
    int *intList = (int *) malloc (length * sizeof(int));
    UserLinkedListNode *currentNode = list->head;
    for (int i = 0; i < length; i++)
    {
        intList[i] = currentNode->value;
        currentNode = currentNode->next;
    }
    return intList;
}

int getLengthUserLinkedList(UserLinkedList *list)
{
    if (list == NULL || list->length == -1) return -1;
    return list->length;
}

int findFirstUserLinkedList(UserLinkedList *list, int key)
{
    if (list == NULL || list->length <= 0)
    {
        return -1;
    }
    int keyIndex = -1;
    int currentIndex = 0;
    UserLinkedListNode *currentNode = list->head;
    while(currentNode != list->tail)
    {
        if (currentNode->value == key)
        {
            keyIndex = currentIndex; 
            break;
        }
        currentIndex++;
        currentNode = currentNode->next;
    }
    return keyIndex;
}

void printUserLinkedList(UserLinkedList *list)
{
    printf("Linked List Data :");
    if (list == NULL || list->length <= 0)
    {
        puts("Empty.");
        return;
    }
    int length = list->length;
    UserLinkedListNode *currentNode = list->head;
    for (int i = 0; i < length; i++)
    {
        printf("%d", currentNode->value);
        if (i < length - 1) printf(" ");
        currentNode = currentNode->next;
    }
    puts(".");
}

struct UserStack
{
    int *data;
    int capacity;
    int length;
};
const int USER_STACK_DEFAULT_EMPTY_GROWTH_SIZE = 10;

UserStack *createUserStack(int initialCapacity)
{
    if (initialCapacity < 0) initialCapacity = 0;
    UserStack *stack = (UserStack *) malloc(sizeof(UserStack));
    stack->capacity = 0;
    growUserStack(stack, initialCapacity);
    stack->length = 0;
    return stack;
}

void growUserStack(UserStack *stack, int newCapacity)
{
    if (stack == NULL || stack->capacity < 0 || newCapacity == 0 || stack->capacity >= newCapacity)
    {
        return;
    }
    if (stack->capacity == 0)
    {
        stack->data = (int *) malloc(newCapacity * sizeof(int));
    }
    else
    {
        int *newData = (int *) malloc(newCapacity * sizeof(int));
        for (int i = 0; i < stack->length; i++)
        {
            newData[i] = stack->data[i];
        }
        free(stack->data);
        stack->data = newData;
    }
    stack->capacity = newCapacity;
    return;
}

int peekUserStack(UserStack *stack)
{
    if (stack == NULL || stack->length <= 0)
    {
        return INT_MIN;
    }
    return stack->data[stack->length - 1];
}

int popUserStack(UserStack *stack)
{
    if (stack == NULL || stack->length <= 0)
    {
        return INT_MIN;
    }
    stack->length--;
    return stack->data[stack->length];
}

int pushUserStack(UserStack *stack, int item)
{
    if (stack == NULL || stack->capacity < 0)
    {
        return 0;
    }
    if (stack->capacity == 0)
    {
        growUserStack(stack, USER_STACK_DEFAULT_EMPTY_GROWTH_SIZE);
    }
    else if (stack->length == stack->capacity)
    {
        growUserStack(stack, stack->capacity * 2);
    }
    stack->data[stack->length] = item;
    stack->length++;
    return 1;
}

int emptyUserStack(UserStack *stack)
{
    if (stack == NULL || stack->length < 0)
    {
        return 0;
    }
    while (stack->length > 0)
    {
        popUserStack(stack);
    }
    return 1;
}

UserStack *deallocateUserStack(UserStack *stack)
{
    if (stack == NULL || stack->capacity < 0)
    { 
        return NULL;
    }
    free(stack->data);
    stack->data = NULL;
    stack->capacity = stack->length = -1;
    free(stack);
    return NULL;
}

int *getDeepListUserStack(UserStack *stack)
{
    if (stack == NULL || stack->length < 0)
    {
        return NULL;
    }
    int length = stack->length;
    int *list = (int *) malloc(length * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        list[i] = stack->data[i];
    }
    return list;
}

int getCapacityUserStack(UserStack *stack)
{
    if (stack == NULL || stack->capacity < 0)
    {
        return -1;
    }
    return stack->capacity;
}

int getLengthUserStack(UserStack *stack)
{
    if (stack == NULL || stack->length < 0)
    {
        return -1;
    }
    return stack->length;
}

struct UserQueue
{
    UserLinkedList *list;
    int length;
};

UserQueue *createUserQueue()
{
    UserQueue *queue = (UserQueue *) malloc(sizeof(UserQueue));
    queue->list = createUserLinkedList();
    queue->length = 0;
    return queue;
}

int peekUserQueue(UserQueue *queue)
{
    if (queue == NULL || queue->length <= 0)
    {
        return INT_MIN;
    }
    return getValueUserLinkedList(queue->list, 0);
}

int popUserQueue(UserQueue *queue)
{
    if (queue == NULL || queue->length <= 0)
    {
        return INT_MIN;
    }
    int value = getValueUserLinkedList(queue->list, 0);
    deleteFirstUserLinkedList(queue->list);
    queue->length--;
    return value;
}

int pushUserQueue(UserQueue *queue, int item)
{
    if (queue == NULL || queue->length < 0)
    {
        return 0;
    }
    insertLastUserLinkedList(queue->list, item);
    queue->length++;
    return 1;
}

int emptyUserQueue(UserQueue *queue)
{
    if (queue == NULL || queue->length < 0)
    {
        return 0;
    }
    while(queue->length > 0)
    {
        deleteLastUserLinkedList(queue->list);
        queue->length--;
    }
    return 1;
}

UserQueue *deallocateUserQueue(UserQueue *queue)
{
    if (queue == NULL || queue->list == NULL || queue->length < 0)
    {
        return NULL;
    }
    queue->list = deallocateUserLinkedList(queue->list);
    queue->length = -1;
    free(queue);
    return NULL;
}

int *getDeepListUserQueue(UserQueue *queue)
{
    if (queue == NULL || queue->length <= 0)
    {
        return NULL;
    }
    return getDeepListUserLinkedList(queue->list);
}

int getLengthUserQueue(UserQueue *queue)
{
    if (queue == NULL || queue->length < 0)
    {
        return -1;
    }
    return queue->length;
}