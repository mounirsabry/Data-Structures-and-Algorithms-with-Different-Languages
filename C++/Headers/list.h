//List data structure, part of the datastructures_mounir namepsace.
//List is doubly linked list.
#ifndef LIST_H
#define LIST_H

namespace datastructures_mounir
{   
    template <typename T> class List;
    template <typename T> bool operator== (const List<T> &list1, const List<T> &list2);

    template <typename T>
    class List
    {
    private:
        class ListNode;
    public:
        class Iterator;
        List();
        //Copy constructor, deep copy the parameter list into the list.
        //Relies on the assignemt operator of the given type.
        List(const List<T> &otherList);
        ~List();
        //Assignment Operator, deep copy the parameter list into the list.
        //Relies on the assignment operator of the given type.
        List<T> &operator =(const List<T> &otherList);
        //Clears all the elements in the list.
        //All iterators referencing elements in the list are invaliated.
        //Length will be zero after the function call.
        void clear();
        int getLength() const;
        bool isEmpty() const;
        //Searches the list for the first instance of the item
        //given, relies on the == operator on comparsion.
        //Returns an iterator pointing to that element.
        //Sequential Search, the algorithm does not cut excpet
        //when the key item is found, otherwise, the algorithm
        //iterates through the whole list.
        List<T>::Iterator findSequential(const T &keyItem);
        //Searches the list for an instance of the key item
        //given, relies on the == operator on comparsion.
        //Returns an iterator pointing to that element.
        //Binary Search, the list must be sorted.
        //The function does not sort the list nor check if sorted.
        //If the function run on unsorted list, the result will be unpredictable.
        //Iterative Implementation.
        List<T>::Iterator findBinary(const T &keyItem);
        //Returns an iterator points to the first element in the list.
        List<T>::Iterator begin() const;
        //Returns an iterator points to the last element in the list.
        List<T>::Iterator last() const;
        //Returns an iterator points to the end of the list.
        //The end is located after the last element in the list.
        //end is a valid iterator, however its value is not valid.
        List<T>::Iterator end() const;
        T &front() const;
        T &back() const;
        //Insert the item at the location iterator, the new element
        //is inserted so that it exists before the location element.
        //Returns true if the insertion was successful, 
        //false otherwise.
        //The insertion fails if not enough memory or invalid location.
        bool insert(const List<T>::Iterator &location, const T &item);
        //Insert the new item at the end of the list.
        //Returns true if the insertion was successful, 
        //false otherwise.
        bool pushBack(const T &item);
        //Insert the new item at the front(start) of the list.
        //Returns true if the inesrtion was successful, 
        //false otherwise.
        bool pushFront(const T &item);
        //Removes the last element in the list (if exists).
        void popBack();
        //Removes the first element in the list (if exists).
        void popFront();
        //Returns true if the deletion was successful, false
        //otherwise.
        bool erase(const List<T>::Iterator &location);
        //Swaps the content of the nodes pointed to by the iterators.
        //The iterators are unaffected directly by the function.
        //After the function call, dereference the iterators will yield
        //the new swapped items.
        //You cannot swap an iterator pointing to end(), function will return.
        void swap(const List<T>::Iterator &iter1, const List<T>::Iterator &iter2);
        //In-place sort.
        void sortInsertionSort();
        //In-place sort.
        void sortBubbleSort();
        //Out-of-place sort.
        void sortMergeSort();
        friend bool operator== <T>(const List<T> &list1, const List<T> &list2);
    private:
        List<T>::ListNode *head;
        List<T>::ListNode *tail;
        List<T>::ListNode *endNode;
        int length;
        List<T>::ListNode *getNodeByIndex(int index) const;
        void swap(const List<T>::ListNode &node1, const List<T>::ListNode &node2);
        List<T> mergeSortUtil(const List<T> &list, int minIndex, int maxIndex) const;
        List<T> merge(const List<T> &list1, const List<T> &list2) const;
    };

    template <typename T>
    class List<T>::ListNode
    {
    public:
        ListNode();
        ListNode(const T &theData, List<T>::ListNode *thePrevious, List<T>::ListNode *theNext);
        T &getData();
        const T &getDataConst() const;
        List<T>::ListNode *getPrevious() const;
        List<T>::ListNode *getNext() const;
        void setData(const T &newData);
        void setPrevious(List<T>::ListNode *newPrevious);
        void setNext(List<T>::ListNode *newNext);
        friend bool operator== (const List<T>::ListNode &node1, const List<T>::ListNode &node2)
        {
            if (node1.getPrevious() != node2.getPrevious()
            ||  node2.getData() != node2.getData()
            ||  node1.getNext() != node2.getNext())
                return false;
            return true;
        }
    private:
        T data;
        List<T>::ListNode *previous;
        List<T>::ListNode *next;
    };

    template <typename T>
    class List<T>::Iterator
    {
    public:
        //Parameterized Constructor.
        Iterator(typename List<T>::ListNode *node);
        //Prefix increment operator.
        List<T>::Iterator &operator++ ();
        //Postfix increment operator.
        List<T>::Iterator operator++ (int);
        //Prefix increment operator.
        List<T>::Iterator &operator-- ();
        //Postfix increment operator.
        List<T>::Iterator operator-- (int);

        //Does not modify the calling object.
        friend bool operator== (const List<T>::Iterator &iter1, const List<T>::Iterator &iter2)
        {
            if (iter1.nodePointer == iter2.nodePointer)
                return true;
            else
                return false;
        }

        //Does not modify the calling object.
        friend bool operator!= (const List<T>::Iterator &iter1, const List<T>::Iterator &iter2)
        {
            return !(iter1 == iter2);
        }

        T &operator* () const;
        typename List<T>::ListNode *getNode() const;
    private:
        List<T>::ListNode *nodePointer;
    };
}

#endif