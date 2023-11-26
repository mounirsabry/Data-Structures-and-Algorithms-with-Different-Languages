//Program to test and use the data structures header and cpp files.
#include <iostream>
#include "Headers/data_structures.h"
using namespace datastructures_mounir;

template <typename T>
void printVector(const Vector<T> &vector);

template <typename T>
void printList(const List<T> &list);

template <typename T>
void printStack(Stack<T> &stack);

template <typename T>
void printQueue(Queue<T> &queue);

int main()
{
    std::cout << "------------------------------" << std::endl;
    //Vector Version 1.0.
    /* std::cout << "Vector Testing Begin." << std::endl << std::endl;
    Vector<int> vector1;
    std::cout << "Is Vector Empty: " << vector1.isEmpty() << std::endl;
    std::cout << vector1.getCapacity() << " " << vector1.getLength() << std::endl;
    std::cout << std::endl;

    vector1.pushBack(10);
    vector1.pushBack(20);
    printVector(vector1);
    std::cout << "Is Vector Empty: " << vector1.isEmpty() << std::endl;
    std::cout << vector1.getCapacity() << " " << vector1.getLength() << std::endl;
    std::cout << std::endl;

    vector1.pushBack(30);
    vector1.insert(0, 5);
    printVector(vector1);
    std::cout << vector1.getCapacity() << " " << vector1.getLength() << std::endl;
    std::cout << std::endl;
    std::cout << "Vector front: " << vector1.front() << " Vector back: " << vector1.back() << std::endl;

    vector1.clear();
    //std::cout << vector1[0] << std::endl;
    try
    {
        std::cout << vector1.at(0) << std::endl;
    }
    catch (std::out_of_range)
    {
        std::cout << "Vector threw out of range exception." << std::endl;
    }
    std::cout << vector1.getCapacity() << " " << vector1.getLength() << std::endl;
    std::cout << std::endl;

    vector1.reserve(100);
    vector1.reserve(50);
    std::cout << vector1.getCapacity() << " " << vector1.getLength() << std::endl;

    std::cout << "Erase Test." << std::endl;
    for (int i = 0; i < 4; i++)
        vector1.pushBack(i + 1);
    printVector(vector1);
    std::cout << vector1.getCapacity() << " " << vector1.getLength() << std::endl;
    vector1.erase(0);
    vector1.erase(1);
    vector1.erase(2);
    vector1.erase(1);
    vector1.erase(0);
    printVector(vector1);
    std::cout << vector1.getCapacity() << " " << vector1.getLength() << std::endl;

    std::cout << "Vector Testing End." << std::endl << std::endl; */
    //Vector Version 2.0.
    /*
    std::cout << "Vector Testing Begin." << std::endl << std::endl;

    Vector<int> vector;
    std::cout << "Is vector empty: " << vector.isEmpty() << std::endl;
    std::cout << "Vector Length: " << vector.getLength() << std::endl;
    std::cout << "Vector Capacity: " << vector.getCapacity() << std::endl;

    vector.reserve(15);
    std::cout << "Vector Capacity: " << vector.getCapacity() << std::endl;
    printVector(vector);

    vector.pushBack(1);
    vector.pushBack(2);
    Vector<int>::Iterator iter = vector.pushBack(10);
    std::cout << *iter << " " << *(iter + 1) << std::endl;
    iter--;
    std::cout << *iter << " " << *(iter - 1) << std::endl;

    std::cout << "Vector Length: " << vector.getLength() << std::endl;
    printVector(vector);

    iter = vector.insert(iter, 3);
    iter = vector.insert(iter, 4);
    vector.erase(vector.begin());
    vector.erase(vector.begin() + 1);

    std::cout << "After insertion and deletion." << std::endl;
    std::cout << "Vector Length: " << vector.getLength() << std::endl;
    printVector(vector);

    std::cout << "Is 4 found? " ;
    auto location4 = vector.find(4);
    if (location4 != vector.end())
        std::cout << "Yes at location: " << location4.getIndex() << std::endl;
    else
        std::cout << "No." << std::endl;

    std::cout << "Is 20 found? ";
    auto location20 = vector.find(20);
    if (location20 != vector.end())
        std::cout << "Yes at location: " << location20.getIndex() << std::endl;
    else
        std::cout << "No." << std::endl;

    auto iter1 = vector.begin();
    auto iter2 = iter1 + 1;

    std::cout << "iter1 index: " << iter1.getIndex() << ", value: " << *iter1 << std::endl;
    std::cout << "iter2 index: " << iter2.getIndex() << ", value: " << *iter2 << std::endl;
    std::cout << (iter1 == iter2) << " " << (iter1 != iter2) << std::endl;
    std::cout << (iter1 < iter2) << " " << (iter1 > iter2) << std::endl;
    std::cout << (iter1 <= iter2) << " " << (iter1 >= iter2) << std::endl;

    iter1 += 1;

    std::cout << "iter1 index: " << iter1.getIndex() << ", value: " << *iter1 << std::endl;
    std::cout << "iter2 index: " << iter2.getIndex() << ", value: " << *iter2 << std::endl;
    std::cout << (iter1 == iter2) << " " << (iter1 != iter2) << std::endl;
    std::cout << (iter1 < iter2) << " " << (iter1 > iter2) << std::endl;
    std::cout << (iter1 <= iter2) << " " << (iter1 >= iter2) << std::endl;

    std::cout << "Vector Testing End." << std::endl << std::endl;
    */

    //List version 1.0
    /*  std::cout << "List Testing Begin." << std::endl << std::endl;

    List<int> list;
    std::cout << "Is the list empty: " << list.isEmpty() << std::endl;
    std::cout << "Empty list length: " << list.getLength() << std::endl;

    list.pushBack(10);
    list.pushBack(20);
    list.pushFront(2);
    list.pushFront(1);

    std::cout << "After pushing list length: " << list.getLength() << std::endl;
    printList(list);

    ListNode<int> *findNode1 = list.find(10);
    list.insert(findNode1, 5);
    list.insert(findNode1, 7);

    std::cout << "After pushing list length: " << list.getLength() << std::endl;
    printList(list);

    std::cout << "list begin: " << list.begin()->getData() << std::endl;
    std::cout << "list last: " << list.last()->getData() << std::endl;
    std::cout << "list front: " << list.front() << std::endl;
    std::cout << "list back: " << list.back() << std::endl;

    list.popBack();
    list.popFront();
    list.erase(findNode1);
    findNode1 = NULL;
    std::cout << "After popping back & front, erasing 10." << std::endl;
    std::cout << "List length: " << list.getLength() << std::endl;
    printList(list);

    std::cout << "Testing deep copy copy constructor and assignment operator." << std::endl;
    List<int> copyList(list); //Copy constructor;
    ListNode<int> *findNode2 = copyList.find(5);
    findNode1 = list.find(5);

    findNode1->setData(11);
    std::cout << "After changing the value of the node which contains 5 in list." << std::endl;
    printList(list);
    printList(copyList);

    findNode2->setData(22);
    std::cout << "After changing the value of the node which contains 5 in copy list." << std::endl;
    printList(list);
    printList(copyList);

    copyList = list;
    findNode2 = copyList.find(11);

    std::cout << "Testing assignment operator 1." << std::endl;
    printList(list);
    printList(copyList);
    
    findNode2->setData(33);
    std::cout << "Testing assignment operator 2." << std::endl;
    printList(list);
    printList(copyList);

    list.clear();
    std::cout << "After clearing list." << std::endl;
    printList(list);
    printList(copyList);

    std::cout << "List Testing End." << std::endl << std::endl; */

    //List Version 2.0.
    std::cout << "List Testing Begin." << std::endl << std::endl;

    List<int> list1;
    std::cout << "Is list empty: " << list1.isEmpty() << std::endl;
    std::cout << "List Length: " << list1.getLength() << std::endl;
    printList(list1);

    auto iter1 = list1.begin();
    if (iter1 == list1.end())
        std::cout << "begin() is end()." << std::endl;

    iter1 = list1.last();
    if (iter1 == list1.end())
        std::cout << "last() is end()." << std::endl;

    iter1 = list1.end();
    if (iter1 == list1.end())
        std::cout << "end() is end()." << std::endl;

    list1.pushBack(1);
    list1.pushBack(2);

    std::cout << "List length: " << list1.getLength() << std::endl;
    printList(list1);

    list1.pushFront(0);
    std::cout << "List length: " << list1.getLength() << std::endl;
    printList(list1);
    list1.pushBack(3);
    list1.insert(list1.last(), 22);
    list1.insert(list1.begin(), -1);
    list1.insert(list1.end(), 33);

    std::cout << "List length: " << list1.getLength() << std::endl;
    printList(list1);
    std::cout << "Front(): " << list1.front() << std::endl;
    std::cout << "Back(): " << list1.back() << std::endl;

    List<int> list2(list1);
    std::cout << "list1 == list2: " << (list1 == list2) << std::endl;

    list2 = list1;
    std::cout << "list1 == list2: " << (list1 == list2) << std::endl;

    list1.erase(list1.begin());
    iter1 = list1.find(22);
    auto temp = iter1;
    temp++;
    list1.erase(iter1);
    list1.erase(temp);
    list1.erase(list1.last());
    list1.popBack();
    list1.popFront();

    std::cout << "List length: " << list1.getLength() << std::endl;
    printList(list1);
    std::cout << "Front(): " << list1.front() << std::endl;
    std::cout << "Back(): " << list1.back() << std::endl;

    std::cout << "list1 == list2: " << (list1 == list2) << std::endl;
    printList(list2);

    std::cout << std::endl << "List Testing end." << std::endl << std::endl;
    
    /* std::cout << "Stack Testing Begin." << std::endl << std::endl;

    Stack<int> stack;
    std::cout << "Is stack empty: " << stack.isEmpty() << std::endl;
    std::cout << "stack length: " << stack.getLength() << std::endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "After inserting 3 elements." << std::endl;
    std::cout << "Stack length: " << stack.getLength() << std::endl;
    printStack(stack);

    std::cout << "After printing the stack." << std::endl;
    std::cout << "Stack length: " << stack.getLength() << std::endl;
    printStack(stack);

    std::cout << "printing the stack involves the functions top and pop." << std::endl;
    stack.clear();
    std::cout << "After clearing the stack." << std::endl;
    std::cout << "Stack length: " << stack.getLength() << std::endl;
    printStack(stack);

    std::cout << std::endl << "Stack Testing End." << std::endl << std::endl;

    std::cout << "Queue Testing Begin." << std::endl << std::endl;

    Queue<int> queue;
    std::cout << "Is Queue empty: " << queue.isEmpty() << std::endl;
    std::cout << "Queue Length: " << queue.getLength() << std::endl;
    printQueue(queue);

    queue.pushBack(1);
    queue.pushBack(2);
    queue.pushBack(3);

    std::cout << "After inserting 3 elements." << std::endl;
    std::cout << "Queue Length: " << queue.getLength() << std::endl;
    printQueue(queue);

    std::cout << "After printing the queue." << std::endl;
    std::cout << "Queue Length: " << queue.getLength() << std::endl;
    printQueue(queue);

    std::cout << "printing the stack involves the functions top and pop." << std::endl;
    queue.clear();
    std::cout << "After clearing the queue." << std::endl;
    std::cout << "Queue Length: " << queue.getLength() << std::endl;
    printQueue(queue);

    std::cout << std::endl << "Queue Testing End." << std::endl << std::endl; */

    std::cout << "End of program." << std::endl;
    std::cout << "------------------------------" << std::endl;
    return 0;
}

template <typename T>
void printVector(const Vector<T> &vector)
{
    //Since I am reading an object not a pointer.
    //vector could never be NULL or nullptr.
    std::cout << "Vector Content: ";
    if (vector.getLength() == 0)
        std::cout << "Empty.";
    else
        std::cout << vector << ".";
    std::cout << std::endl;
}

template <typename T>
void printList(const List<T> &list)
{
    //Since I am reading an object not a pointer.
    //list could never be NULL or nullptr.
    std::cout << "List Content: ";
    if (list.getLength() == 0)
        std::cout << "Empty.";
    else
    {
        for (auto iter = list.begin(); iter != list.last(); iter++)
            std::cout << *iter << " ";
        std::cout << list.back() << ".";
    }
    std::cout << std::endl;
}

template <typename T>
void printStack(Stack<T> &stack)
{
    //Since I am reading an object not a pointer.
    //stack could never be NULL or nullptr.
    std::cout << "Stack Content: ";
    int length = stack.getLength();
    if (length == 0)
        std::cout << "Empty.";
    else
    {
        T *stackContent = new T[length];
        //Extracting the stack content.
        for (int i = 0; i < length; i++)
        {
            stackContent[i] = stack.topConst();
            stack.pop();
        }

        for (int i = 0; i < length - 1; i++)
            std::cout << stackContent[i] << " ";
        std::cout << stackContent[length - 1] << ".";

        for (int i = 0; i < length; i++)
            stack.push(stackContent[length - 1 - i]);
        delete []stackContent;
    }
    std::cout << std::endl;
}

template <typename T>
void printQueue(Queue<T> &queue)
{
    //Since I am reading an object not a pointer.
    //queue could never be NULL or nullptr.
    std::cout << "Queue Content: ";
    int length = queue.getLength();
    if (length == 0)
        std::cout << "Empty.";
    else
    {
        T *queueContent = new T[length];
        //Extracting the queue content.
        for (int i = 0; i < length; i++)
        {
            queueContent[i] = queue.front();
            queue.popFront();
        }

        for (int i = 0; i < length - 1; i++)
            std::cout << queueContent[i] << " ";
        std::cout << queueContent[length - 1] << ".";

        for (int i = 0; i < length; i++)
            queue.pushBack(queueContent[i]);
        delete []queueContent;
    }
    std::cout << std::endl;
}