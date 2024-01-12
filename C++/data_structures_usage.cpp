//Program to test and use the data structures header and cpp files.
#include <iostream>
#include <chrono>
#include <random>
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

std::mt19937 *initializeRandomNumberGenerator();
int getIntRandomLimit(std::mt19937 *generator, int start, int end);
void fillIntVectorRandomLimits(Vector<int> &vector, int numberOfElements, std::mt19937 *generator,
    int start, int end);
void fillIntListRandomLimits(List<int> &list, int numberOfElements, std::mt19937 *generator,
    int start, int end);

int main()
{
    std::mt19937 *generator = initializeRandomNumberGenerator();
    const int START_LIMIT = 1;
    const int END_LIMIT = 40;

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
    auto location4 = vector.findSequential(4);
    if (location4 != vector.end())
        std::cout << "Yes at location: " << location4.getIndex() << std::endl;
    else
        std::cout << "No." << std::endl;

    std::cout << "Is 20 found? ";
    auto location20 = vector.findSequential(20);
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

    //Vector swap, sorting, and searching.
    /*
    std::cout << "Vector Testing Begin." << std::endl;
    Vector<int> vector1;
    fillIntVectorRandomLimits(vector1, 10, generator, START_LIMIT, END_LIMIT);
    int key = getIntRandomLimit(generator, START_LIMIT, END_LIMIT);

    std::cout << "Vector1 before sorting." << std::endl;
    printVector(vector1);
    std::cout << "The key: " << key << std::endl;

    Vector<int>::Iterator iter1 = vector1.begin();
    Vector<int>::Iterator iter2 = vector1.last();
    std::cout << *iter1 << " " << *iter2 << std::endl;
    vector1.swap(iter1, iter2);
    std::cout << "Vector1 after swapping first and last." << std::endl;
    printVector(vector1);
    std::cout << *iter1 << " " << *iter2 << std::endl << std::endl;

    Vector<int>::Iterator iter = vector1.findSequential(key);
    std::cout << "Sequential Search." << std::endl;
    if (iter != vector1.end())
        std::cout << "Key is found in the vector." << std::endl;
    else
        std::cout << "Key is not found in the vector." << std::endl;

    iter = vector1.findBinary(key);
    std::cout << std::endl << "Binary Search." << std::endl;
    if (iter != vector1.end())
        std::cout << "Key is found in the vector." << std::endl;
    else
        std::cout << "Key is not found in the vector." << std::endl;

    vector1.sortMergeSort();

    std::cout << std::endl << "Vector1 after sorting." << std::endl;
    printVector(vector1);

    iter = vector1.findSequential(key);
    std::cout << "Sequential Search." << std::endl;
    if (iter != vector1.end())
        std::cout << "Key is found in the vector." << std::endl;
    else
        std::cout << "Key is not found in the vector." << std::endl;

    iter = vector1.findBinary(key);
    std::cout << std::endl << "Binary Search." << std::endl;
    if (iter != vector1.end())
        std::cout << "Key is found in the vector." << std::endl;
    else
        std::cout << "Key is not found in the vector." << std::endl;
    std::cout << "Vector Testing End."
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

    ListNode<int> *findNode1 = list.findSequential(10);
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
    ListNode<int> *findNode2 = copyList.findSequential(5);
    findNode1 = list.findSequential(5);

    findNode1->setData(11);
    std::cout << "After changing the value of the node which contains 5 in list." << std::endl;
    printList(list);
    printList(copyList);

    findNode2->setData(22);
    std::cout << "After changing the value of the node which contains 5 in copy list." << std::endl;
    printList(list);
    printList(copyList);

    copyList = list;
    findNode2 = copyList.findSequential(11);

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
    /*
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
    iter1 = list1.findSequential(22);
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
    */
    //List swap, sorting, and searching.
    /*
    std::cout << "List Testing Begin." << std::endl << std::endl;
    List<int> list1;
    fillIntListRandomLimits(list1, 10, generator, START_LIMIT, END_LIMIT);
    int key = getIntRandomLimit(generator, START_LIMIT, END_LIMIT);

    std::cout << "The list unsorted." << std::endl;
    printList(list1);
    std::cout << "Key: " << key << std::endl;

    List<int>::Iterator beginIter = list1.begin();
    List<int>::Iterator lastIter = list1.last();
    std::cout << *beginIter << " " << *lastIter << std::endl;
    list1.swap(beginIter, lastIter);
    std::cout << *beginIter << " " << *lastIter << std::endl;

    std::cout << "The list after swapping begin and last." << std::endl << std::endl;
    printList(list1);

    List<int>::Iterator iter1 = list1.findSequential(key);
    std::cout << "Sequential Search: ";
    if (iter1 != list1.end())
        std::cout << "The key is in the list." << std::endl;
    else
        std::cout << "The key is not in the list." << std::endl;

    iter1 = list1.findBinary(key);
    std::cout << "Binary Search: ";
    if (iter1 != list1.end())
        std::cout << "The key is in the list." << std::endl;
    else
        std::cout << "The key is not in the list." << std::endl;
    
    std::cout << std::endl;
    std::cout << "The list sorted." << std::endl;
    list1.sortMergeSort();
    printList(list1);
    std::cout << std::endl;

    List<int>::Iterator iter2 = list1.findSequential(key);
    std::cout << "Sequential Search: ";
    if (iter2 != list1.end())
        std::cout << "The key is in the list." << std::endl;
    else
        std::cout << "The key is not in the list." << std::endl;
    
    iter2 = list1.findBinary(key);
    std::cout << "Binary Search: ";
    if (iter2 != list1.end())
        std::cout << "The key is in the list." << std::endl;
    else
        std::cout << "The key is not in the list." << std::endl;
    std::cout << std::endl;
    std::cout << "List Testing End." << std::endl;
    */
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

    Vector<int> vect1;
    vect1.pushBack(187);
    vect1.pushBack(54);
    vect1.pushBack(30);
    vect1.pushBack(11);
    vect1.pushBack(22);
    std::cout << vect1 << std::endl;
    vect1.sortQuickSort();
    std::cout << vect1 << std::endl;
    

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

std::mt19937 *initializeRandomNumberGenerator()
{
    /*
        The syntax was copied from the Serge Dundich's answer
        from the stackoverflow website.
        Question name: How to generate a random number in C++?
        Question link: 
        https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c

        The syntax uses the c++11 modern way of generating random numbers instead of rand
        and srand.
        It uses the random device as a pseudo random generator.
        The seed is the sum of the system time and the high resolution clock.
        The uniform distribution is used to make sure that the result was not biased due to the
        usage of % internally in the distribution.
    */
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 *gen = new std::mt19937(seed);
    return gen;
}

int getIntRandomLimit(std::mt19937 *generator, int start, int end)
{
    //return (start + rand() % (end - start + 1));
    std::uniform_int_distribution<unsigned> dist(start, end);
    return dist(*generator);
}

void fillIntVectorRandomLimits(Vector<int> &vector, int numberOfElements, std::mt19937 *generator,
    int start, int end)
{
    std::uniform_int_distribution<unsigned> dist(start, end);
    for (int i = 0; i < numberOfElements; i++)
    {
        vector.pushBack(dist(*generator));
    }
}

void fillIntListRandomLimits(List<int> &list, int numberOfElements, std::mt19937 *generator,
    int start, int end)
{
    std::uniform_int_distribution<unsigned> dist(start, end);
    for (int i = 0; i < numberOfElements; i++)
    {
        list.pushBack(dist(*generator));
    }
}
