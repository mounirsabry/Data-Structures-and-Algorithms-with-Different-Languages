//The implementation file for the list.h file.
#ifndef LIST_CPP
#define LIST_CPP

#include <cstdlib> //For NULL.
#include "../Headers/list.h"

namespace datastructures_mounir
{
    template <typename T>
    ListNode<T>::ListNode()
        : data(NULL), previous(NULL), next(NULL)
    {}

    template <typename T>
    ListNode<T>::ListNode(const T &theData, ListNode *thePrevious, ListNode *theNext)
        : data(theData), previous(thePrevious), next(theNext)
    {}

    template <typename T>
    T &ListNode<T>::getData()
    {
        return data;
    }

    template <typename T>
    const T &ListNode<T>::getDataConst() const
    {
        return data;
    }

    template <typename T>
    ListNode<T> *ListNode<T>::getPrevious() const
    {
        return previous;
    }

    template <typename T>
    ListNode<T> *ListNode<T>::getNext() const
    {
        return next;
    }

    template <typename T>
    void ListNode<T>::setData(const T &newData)
    {
        data = newData;
    }

    template <typename T>
    void ListNode<T>::setPrevious(ListNode<T> *newPrevious)
    {
        previous = newPrevious;
    }

    template <typename T>
    void ListNode<T>::setNext(ListNode<T> *newNext)
    {
        next = newNext;
    }

    template <typename T>
    List<T>::List()
        : head(NULL), tail(NULL), length(0)
    {}

    template <typename T>
    List<T>::List(const List<T> &otherList)
        : head(NULL), tail(NULL), length(0)
    {
        for(ListNode<T> *iter = otherList.head; iter != NULL; iter = iter->getNext())
            pushBack(iter->getData());
    }

    template <typename T>
    List<T>::~List()
    {
        clear();
    }

    template <typename T>
    List<T> &List<T>::operator =(const List<T> &otherList)
    {
        if (this == &otherList)
            return *this;
        clear();
        for (ListNode<T> *iter = otherList.head; iter != NULL; iter = iter->getNext())
            pushBack(iter->getData());
        return *this;
    }

    template <typename T>
    void List<T>::clear()
    {
        if (length == 0)
            return;
        ListNode<T> *discard;
        ListNode<T> *iter = head;
        while (iter != NULL)
        {
            discard = iter;
            iter = iter->getNext();
            delete discard;
        }
        head = NULL;
        tail = NULL;
        length = 0;
    }

    template <typename T>
    int List<T>::getLength() const
    {
        return length;
    }

    template <typename T>
    bool List<T>::isEmpty() const
    {
        return (length <= 0);
        //head == NULL or tail == NULL would also work.
    }

    template <typename T>
    ListNode<T> *List<T>::find(const T &item)
    {
        ListNode<T> *desiredNode = NULL;
        for (ListNode<T> *iter = head; iter != NULL; iter = iter->getNext())
        {
            if (iter->getDataConst() == item)
            {
                desiredNode = iter;
                break;
            }
        }
        return desiredNode;
    }

    template <typename T>
    ListNode<T> *List<T>::begin() const
    {
        return head;
    }

    template <typename T>
    ListNode<T> *List<T>::last() const
    {
        return tail;
    }

    template <typename T>
    T &List<T>::front() const
    {
        return head->getData();
    }

    template <typename T>
    T &List<T>::back() const
    {
        return tail->getData();
    }

    template <typename T>
    ListNode<T> *List<T>::insert(ListNode<T> *location, const T &item)
    {
        if (location == NULL)
            return NULL;
        ListNode<T> *newNode = new ListNode<T>(item, location->getPrevious(), location);
        location->getPrevious()->setNext(newNode);
        location->setPrevious(newNode);
        length++;
        return newNode;
    }

    template <typename T>
    ListNode<T> *List<T>::pushBack(const T &item)
    {
        ListNode<T> *newNode = new ListNode<T>(item, NULL, NULL);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->setPrevious(tail);
            tail->setNext(newNode);
            tail = newNode;
        }
        length++;
        return newNode;
    }

    template <typename T>
    ListNode<T> *List<T>::pushFront(const T &item)
    {
        ListNode<T> *newNode = new ListNode<T>(item, NULL, NULL);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->setNext(head);
            head->setPrevious(newNode);
            head = newNode;
        }
        length++;
        return newNode;
    }

    template <typename T>
    ListNode<T> *List<T>::popBack()
    {
        ListNode<T> *newLastNode = NULL;
        if (tail != NULL) //The list is not empty.
        {
            ListNode<T> *discard = tail;
            tail = tail->getPrevious();
            if (tail != NULL)
                tail->setNext(NULL);
            else //List is empty.
                head = NULL;
            newLastNode = tail;

            delete discard;
            length--;
        }
        return newLastNode;
    }

    template <typename T>
    ListNode<T> *List<T>::popFront()
    {
        ListNode<T> *newFirstNode = NULL;
        if (head != NULL) //The list is not empty.
        {
            ListNode<T> *discard = head;
            head = head->getNext();
            if (head != NULL)
                head->setPrevious(NULL);
            else //List is empty.
                tail = NULL;
            newFirstNode = head;

            delete discard;
            length--;
        }
        return newFirstNode;
    }

    template <typename T>
    bool List<T>::erase(ListNode<T> *location)
    {
        if (location == NULL)
            return false;

        if (location->getPrevious() != NULL) //Not the first node in the list.
            location->getPrevious()->setNext(location->getNext());
        else
            head = head->getNext();

        if (location->getNext() != NULL) //Not the last node in the list.
            location->getNext()->setPrevious(location->getPrevious());
        else
            tail = tail->getPrevious();
        
        delete location;
        length--;
        return true;
    }
}

#endif