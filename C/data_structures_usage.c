#include <stdio.h>
#include <stdlib.h>

#include "Header Files/data_structures_structs.h"

void printIntList(const int *list, int length);
void printIntListOneLine(const int *list, int length);
void printUserStack(UserStack *stack);
void printUserQueue(UserQueue *queue);

int main()
{
    puts("-------------------------------------------------------");
    puts("Hello from Data Structures Usage Main.");
    puts("--------------------------------------");

    /* puts("User Array Section.");
    puts("-------------------");
    UserArray *array1 = createUserArray(0);
    printf("Empty array capacity and length :%d %d.\n", getCapacityUserArray(array1), getLengthUserArray(array1));
    printf("Accessing empty array index 1 :%d.\n", getValueUserArray(array1, 1));
    insertLastUserArray(array1, 10);
    insertFirstUserArray(array1, 5);
    insertItemUserArray(array1, 1, 7);
    insertFirstUserArray(array1, 1);
    insertLastUserArray(array1, 20);
    insertItemUserArray(array1, 2, 234);

    puts("User Array Content after group of insertions.");
    printf("Array capacity and length :%d %d.\n", getCapacityUserArray(array1), getLengthUserArray(array1));
    int *deepList = getDeepListUserArray(array1);
    printIntList(deepList, getLengthUserArray(array1));
    free(deepList); deepList = NULL;
    printUserArray(array1);

    puts("User Array after a group of updates.");
    updateItemUserArray(array1, 0, 2);
    updateItemUserArray(array1, 10, 1000);
    updateItemUserArray(array1, 2, 334);
    printUserArray(array1);

    deleteFirstUserArray(array1);
    deleteLastUserArray(array1);
    deleteItemUserArray(array1, 1);
    puts("User Array after a group of deletion.");
    printf("Array capacity and length :%d %d.\n", getCapacityUserArray(array1), getLengthUserArray(array1));
    printUserArray(array1);

    printf("Is %d exists in the array :%d.\n", 10, findFirstUserArray(array1, 10));
    printf("Is %d exists in the array :%d.\n", 20, findFirstUserArray(array1, 20));

    growUserArray(array1, 1000);
    puts("User Array after growing capacity to 1000.");
    printf("Array capacity and length :%d %d.\n", getCapacityUserArray(array1), getLengthUserArray(array1));
    printUserArray(array1);

    printf("Array capacity and length :%d %d.\n", getCapacityUserArray(array1), getLengthUserArray(array1));
    printUserArray(array1);
    
    puts("--------------------------------------------------");
    puts("Deallocating the Array.");
    puts("-----------------------");
    deallocateUserArray(array1);
    printf("deallocated array capacity and length :%d %d.\n", getCapacityUserArray(array1), getLengthUserArray(array1));
    printf("Array Pointer Value :%p\n", array1);
    array1 = deallocateUserArray(array1);
    if (array1 != NULL)
    {
        printf("Empty array capacity and length :%d %d.\n", getCapacityUserArray(array1), getLengthUserArray(array1));
        printf("Array Pointer Value :%p\n", array1);
    } */
    /* puts("User Linked List Section.");
    puts("-------------------------");

    UserLinkedList *linkedList = createUserLinkedList();
    printf("Empty Linked List Length :%d.\n", getLengthUserLinkedList(linkedList));
    printUserLinkedList(linkedList);

    insertFirstUserLinkedList(linkedList, 1);
    insertLastUserLinkedList(linkedList, 2);
    insertItemUserLinkedList(linkedList, 2, 3);
    printf("After insertion 1, Linked List Length :%d.\n", getLengthUserLinkedList(linkedList));
    printUserLinkedList(linkedList);
    int *deepList = getDeepListUserLinkedList(linkedList);
    printf("Testing One Line Function :");
    printIntListOneLine(deepList, getLengthUserLinkedList(linkedList));
    puts("");
    free(deepList); deepList = NULL;

    insertItemUserLinkedList(linkedList, 1, 10);
    insertItemUserLinkedList(linkedList, 2, 20);
    insertFirstUserLinkedList(linkedList, 100);
    insertLastUserLinkedList(linkedList, 200);
    printf("After insertion 2, Linked List Length :%d.\n", getLengthUserLinkedList(linkedList));
    printUserLinkedList(linkedList);

    updateItemUserLinkedList(linkedList, 0, 1000);
    updateItemUserLinkedList(linkedList, 6, 2000);
    updateItemUserLinkedList(linkedList, 4, 23);
    printf("After update, Linked List Length :%d.\n", getLengthUserLinkedList(linkedList));
    printUserLinkedList(linkedList);

    deleteFirstUserLinkedList(linkedList);
    deleteLastUserLinkedList(linkedList);
    deleteItemUserLinkedList(linkedList, 3);
    printf("After deletion, Linked List Length :%d.\n", getLengthUserLinkedList(linkedList));
    printUserLinkedList(linkedList);

    deepList = getDeepListUserLinkedList(linkedList);
    printIntList(deepList, getLengthUserLinkedList(linkedList));
    free(deepList); deepList = NULL;

    printf("Index of 10 :%d, Index of 23 :%d.\n"
    , findFirstUserLinkedList(linkedList, 10)
    , findFirstUserLinkedList(linkedList, 23));

    puts("Linked List Deallocation.");
    deallocateUserLinkedList(linkedList);
    printf("Length :%d\n", getLengthUserLinkedList(linkedList));
    printf("list[0] :%d\n", getValueUserLinkedList(linkedList, 0));
    printf("list[1] :%d\n", getValueUserLinkedList(linkedList, 1)); */
    /* puts("User Stack Section.");
    UserStack *stack = createUserStack(-599);
    printf("Empty Stack capacity :%d, length :%d\n", getCapacityUserStack(stack), getLengthUserStack(stack));
    printf("stack peek :%d, stack pop :%d.\n", peekUserStack(stack), popUserStack(stack));

    growUserStack(stack, 1);
    printf("After grow capacity to 50, Stack capacity :%d, length :%d\n", getCapacityUserStack(stack), getLengthUserStack(stack));
    printf("stack peek :%d, stack pop :%d.\n", peekUserStack(stack), popUserStack(stack));

    pushUserStack(stack, 10);
    pushUserStack(stack, 20);
    printf("After pushing 10 and 20, Stack capacity :%d, length :%d\n", getCapacityUserStack(stack), getLengthUserStack(stack));
    printUserStack(stack);

    printf("stack peek :%d.\n", peekUserStack(stack));
    printf("stack pop :%d.\n", popUserStack(stack));
    printf("stack peek :%d.\n", peekUserStack(stack));
    printf("stack pop :%d.\n", popUserStack(stack));
    printf("stack peek :%d.\n", peekUserStack(stack));
    printf("stack pop :%d.\n", popUserStack(stack));

    printf("After popping all data, Stack capacity :%d, length :%d\n", getCapacityUserStack(stack), getLengthUserStack(stack));
    printUserStack(stack);

    pushUserStack(stack, 1);
    pushUserStack(stack, 2);
    pushUserStack(stack, 3);
    emptyUserStack(stack);
    printf("Empty the stack after inserting 1, 2, and 3, Stack capacity :%d, length :%d\n"
    , getCapacityUserStack(stack), getLengthUserStack(stack));
    printUserStack(stack);

    puts("User Stack Deallocation.");
    stack = deallocateUserStack(stack);
    printf("Stack capacity :%d, length :%d\n", getCapacityUserStack(stack), getLengthUserStack(stack));
    printUserStack(stack); */
    puts("User Queue Section.");
    UserQueue *q1 = createUserQueue();
    printf("Empty queue length :%d\n", getLengthUserQueue(q1));
    printUserQueue(q1);

    pushUserQueue(q1, 101);
    pushUserQueue(q1, 202);
    printf("After pushing, queue length :%d\n", getLengthUserQueue(q1));
    printUserQueue(q1);

    printf("Queue peek :%d\n", peekUserQueue(q1));
    printf("Queue pop :%d\n", popUserQueue(q1));
    printf("Queue peek :%d\n", peekUserQueue(q1));
    printf("Queue pop :%d\n", popUserQueue(q1));
    printf("After peeking and popping, queue length :%d\n", getLengthUserQueue(q1));
    printUserQueue(q1);

    pushUserQueue(q1, 111);
    pushUserQueue(q1, 222);
    pushUserQueue(q1, 333);
    printf("After pushing the stack Again, queue length :%d\n", getLengthUserQueue(q1));
    printUserQueue(q1);

    emptyUserQueue(q1);
    printf("After emptying the queue, queue length :%d\n", getLengthUserQueue(q1));
    printUserQueue(q1);

    puts("User Queue Deallocation.");
    q1 = deallocateUserQueue(q1);
    printf("User Queue length :%d\n", getLengthUserQueue(q1));
    printUserQueue(q1);

    q1 = deallocateUserQueue(q1);
    printf("User Queue length :%d\n", getLengthUserQueue(q1));
    printUserQueue(q1);
    

    puts("-------------------------------------------------------");
    return 0;
}

void printIntList(const int *list, int length)
{
    printf("Int List :");
    if (list == NULL || length == 0)
    {
        puts("Empty List.");
        return;
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d", list[i]);
        if (i != length - 1)
        {
            printf(" ");
        }
    }
    puts(".");
    return;
}

void printIntListOneLine(const int *list, int length)
{
    if (list == NULL || length == 0) return;
    for (int i = 0; i < length; i++)
    {
        printf("%d", list[i]);
        if (i < length - 1)
        {
            printf(" ");
        }
    }
    return;
}

void printUserStack(UserStack *stack)
{
    printf("User Stack Data :");
    if (stack == NULL || getLengthUserStack(stack) <= 0)
    {
        puts("Empty.");
        return;
    }
    int *deepList = getDeepListUserStack(stack);
    printIntListOneLine(deepList, getLengthUserStack(stack));
    puts(".");
    free(deepList);
    return;
}

void printUserQueue(UserQueue *queue)
{
    printf("User Queue Data :");
    if (queue == NULL || getLengthUserQueue(queue) <= 0)
    {
        puts("Empty.");
        return;
    }
    int *deepList = getDeepListUserQueue(queue);
    printIntListOneLine(deepList, getLengthUserQueue(queue));
    puts(".");
    free(deepList);
    return;
}