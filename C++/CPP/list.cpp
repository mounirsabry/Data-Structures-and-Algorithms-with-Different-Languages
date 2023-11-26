//The implementation file for the list.h file.
#ifndef LIST_CPP
#define LIST_CPP

#include <cstdlib>
#include "../Headers/list.h"

namespace datastructures_mounir
{
    template <typename T>
    List<T>::List()
    {
        endNode = new List<T>::ListNode(0, nullptr, nullptr);
        head = endNode;
        tail = endNode;
        length = 0;
    }

    template <typename T>
    List<T>::List(const List<T> &otherList)
    {
        endNode = new List<T>::ListNode(0, nullptr, nullptr);
        head = endNode;
        tail = endNode;
        length = 0;
        List<T>::ListNode *nodeIter;
        for(nodeIter = otherList.head; nodeIter != otherList.endNode; nodeIter = nodeIter->getNext())
            pushBack(nodeIter->getDataConst());
    }

    template <typename T>
    List<T>::~List()
    {
        clear();
        delete endNode;
    }

    template <typename T>
    List<T> &List<T>::operator =(const List<T> &otherList)
    {
        if (this == &otherList)
            return *this;
        clear();
        List<T>::ListNode *nodeIter;
        for (nodeIter = otherList.head; nodeIter != otherList.endNode; nodeIter = nodeIter->getNext())
            pushBack(nodeIter->getDataConst());
        return *this;
    }

    template <typename T>
    void List<T>::clear()
    {
        if (length == 0)
            return;
        List<T>::ListNode *discard;
        List<T>::ListNode *nodeIter = head;
        while (nodeIter != endNode)
        {
            discard = nodeIter;
            nodeIter = nodeIter->getNext();
            delete discard;
        }
        head = endNode;
        tail = endNode;
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
        //head == endNode or tail == endNode should also work.
    }

    template <typename T>
    typename List<T>::Iterator List<T>::find(const T &item)
    {
        List<T>::ListNode *desiredNode = endNode;
        for (List<T>::ListNode *nodeIter = head; nodeIter != endNode; nodeIter = nodeIter->getNext())
        {
            if (nodeIter->getDataConst() == item)
            {
                desiredNode = nodeIter;
                break;
            }
        }
        return List<T>::Iterator(desiredNode);
    }

    template <typename T>
    typename List<T>::Iterator List<T>::begin() const
    {
        return List<T>::Iterator(head);
    }

    template <typename T>
    typename List<T>::Iterator List<T>::last() const
    {
        return List<T>::Iterator(tail);
    }

    template <typename T>
    typename List<T>::Iterator List<T>::end() const
    {
        return List<T>::Iterator(endNode);
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
    bool List<T>::insert(const List<T>::Iterator &location, const T &item)
    {
        if (location.getNode() == nullptr)
            return false;
        List<T>::ListNode *locationNode = location.getNode();

        List<T>::ListNode *newNode;
        try
        {
            newNode = new List<T>::ListNode(item, locationNode->getPrevious(), locationNode);
        }
        catch (std::bad_alloc e)
        {
            return false;
        }

        if (locationNode->getPrevious() != nullptr)
            locationNode->getPrevious()->setNext(newNode);
        else //Insertion at the start of the list.
            head = newNode;
        locationNode->setPrevious(newNode);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else if (location == endNode)
            tail = newNode;
        length++;
        return true;
    }

    template <typename T>
    bool List<T>::pushBack(const T &item)
    {
        return insert(end(), item);
    }

    template <typename T>
    bool List<T>::pushFront(const T &item)
    {
        return insert(begin(), item);
    }

    template <typename T>
    void List<T>::popBack()
    {
        erase(last());
    }

    template <typename T>
    void List<T>::popFront()
    {
        erase(begin());
    }

    template <typename T>
    bool List<T>::erase(const List<T>::Iterator &location)
    {
        List<T>::ListNode *locationNode = location.getNode();
        if (locationNode == nullptr || locationNode == endNode)
            return false;

        if (locationNode->getPrevious() != nullptr) //Not the head node.
            locationNode->getPrevious()->setNext(locationNode->getNext());
        else //The head node.
            head = head->getNext();

        if (locationNode->getNext() == endNode) //The tail node.
        {
            
            if (tail->getPrevious() != nullptr)
            {
                endNode->setPrevious(locationNode->getPrevious());
                tail = tail->getPrevious();
            }
            else //The last node remaining in the list.
            {
                endNode->setPrevious(nullptr);
                //Replacing nullptr with locationNode->getPrevious()
                //would also work, however nullptr is explicitly mentioned
                //for clearity.
                tail = endNode;
            }
        }
        else //Not the tail node.
            locationNode->getNext()->setPrevious(locationNode->getPrevious());

        delete locationNode;
        length--;
        return true;
    }

    template <typename T>
    bool operator== (const List<T> &list1, const List<T> &list2)
    {
        if (list1.length != list2.length)
            return false;
        typename List<T>::ListNode *nodeIter1 = list1.head;
        typename List<T>::ListNode *nodeIter2 = list2.head;
        for (int i = 0; i < list1.length; i++) //list2.length should also work.
        {
            if (nodeIter1->getData() != nodeIter2->getData())
                return false;
            nodeIter1 = nodeIter1->getNext();
            nodeIter2 = nodeIter2->getNext();
        }
        return true;
    }

    template <typename T>
    List<T>::ListNode::ListNode()
        : data(0), previous(nullptr), next(nullptr)
    {}

    template <typename T>
    List<T>::ListNode::ListNode(const T &theData, 
        typename List<T>::ListNode *thePrevious, typename List<T>::ListNode *theNext)
        : data(theData), previous(thePrevious), next(theNext)
    {}

    template <typename T>
    T &List<T>::ListNode::getData()
    {
        return data;
    }

    template <typename T>
    const T &List<T>::ListNode::getDataConst() const
    {
        return data;
    }

    template <typename T>
    typename List<T>::ListNode *List<T>::ListNode::getPrevious() const
    {
        return previous;
    }

    template <typename T>
    typename List<T>::ListNode *List<T>::ListNode::getNext() const
    {
        return next;
    }

    template <typename T>
    void List<T>::ListNode::setData(const T &newData)
    {
        data = newData;
    }

    template <typename T>
    void List<T>::ListNode::setPrevious(typename List<T>::ListNode *newPrevious)
    {
        previous = newPrevious;
    }

    template <typename T>
    void List<T>::ListNode::setNext(typename List<T>::ListNode *newNext)
    {
        next = newNext;
    }

    template <typename T>
    List<T>::Iterator::Iterator(typename List<T>::ListNode *node)
        :nodePointer(node)
    {}

    template <typename T>
    typename List<T>::Iterator &List<T>::Iterator::operator++ ()
    {
        if (nodePointer->getNext() != nullptr)
            nodePointer = nodePointer.getNext();
        return *this;
    }

    template <typename T>
    typename List<T>::Iterator List<T>::Iterator::operator++ (int)
    {
        List<T>::Iterator temp = *this;
        if (nodePointer->getNext() != nullptr)
            nodePointer = nodePointer->getNext();
        return temp;
    }

    template <typename T>
    typename List<T>::Iterator &List<T>::Iterator::operator-- ()
    {
        if (nodePointer.getPrevious() != nullptr)
            nodePointer = nodePointer->getPrevious();
        return *this;
    }

    template <typename T>
    typename List<T>::Iterator List<T>::Iterator::operator-- (int)
    {
        List<T>::Iterator temp = *this;
        if (nodePointer.getPrevious() != nullptr)
            nodePointer = nodePointer.getPrevious();
        return temp;
    }

    template <typename T>
    T &List<T>::Iterator::operator* () const
    {
        return nodePointer->getData();
    }

    template <typename T>
    typename List<T>::ListNode *List<T>::Iterator::getNode() const
    {
        return nodePointer;
    }
}

#endif