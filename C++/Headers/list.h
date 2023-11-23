//List data structure, part of the datastructures_mounir namepsace.
//List is doubly linked list.
#ifndef LIST_H
#define LIST_H

namespace datastructures_mounir
{
    template <typename T> class ListNode;
    template <typename T> 
    bool operator== (const ListNode<T> &node1, const ListNode<T> &node2);

    template <typename T>
    class ListNode
    {
    public:
        ListNode();
        ListNode(const T &theData, ListNode<T> *thePrevious, ListNode<T> *theNext);
        T &getData();
        const T &getDataConst() const;
        ListNode<T> *getPrevious() const;
        ListNode<T> *getNext() const;
        void setData(const T &newData);
        void setPrevious(ListNode<T> *newPrevious);
        void setNext(ListNode<T> *newNext);
        friend bool operator== <T>(const ListNode<T> &node1, const ListNode<T> &node2);
    private:
        T data;
        ListNode<T> *previous;
        ListNode<T> *next;
    };
    
    template <typename T> class List;
    template <typename T> bool operator== (const List<T> &list1, const List<T> &list2);

    template <typename T>
    class List
    {
    public:
        List();
        //Copy constructor, deep copy the parameter list into the list.
        //Relies on the assignemt operator of the given type.
        List(const List<T> &otherList);
        ~List();
        //Assignment Operator, deep copy the parameter list into the list.
        //Relies on the assignment operator of the given type.
        List<T> &operator =(const List<T> &otherList);
        //Clears all the elements in the list.
        //All indexes/pointers referencing elements in the list are invaliated.
        //Length will be zero after the function call.
        void clear();
        int getLength() const;
        bool isEmpty() const;
        //Searches the list for the first instance of the item
        //given, relies on the == operator on comparsion.
        //Returns the node of the item.
        ListNode<T> *find(const T &item);
        //Returns the first node in the list, if the list is empty
        //then NULL is returned.
        ListNode<T> *begin() const;
        //Returns the last node in the list, the return is valid as long
        //as there is nodes in the list, if the list is empty, then NULL
        //is returned.
        ListNode<T> *last() const;
        T &front() const;
        T &back() const;
        //Insert the item at a new node at the location, the new node
        //is inserted so that it is before the location node in the list.
        //Returns the newly inserted node.
        ListNode<T> *insert(ListNode<T> *location, const T &item);
        //Insert the new item at the end of the list.
        //Returns the index of the newly insertd item.
        ListNode<T> *pushBack(const T &item);
        //Insert the new item at the front(start) of the list.
        //Returns the index of the newly inserted item.
        ListNode<T> *pushFront(const T &item);
        //Removes the last element in the list (if exists).
        //Returns the new last element in the list.
        //If the list is empty before or after the deletion
        //then NULL is returned.
        ListNode<T> *popBack();
        //Removes the first element in the list (if exists).
        //Returns the new first element in the list.
        //If the list is empty before or after the deletion
        //then NULL is returned.
        ListNode<T> *popFront();
        //Returns true if the deletion was successful, false
        //otherwise.
        bool erase(ListNode<T> *location);
        friend bool operator== <T>(const List<T> &list1, const List<T> &list2);
    public:
        ListNode<T> *head;
        ListNode<T> *tail;
        int length;
    };
}

#endif