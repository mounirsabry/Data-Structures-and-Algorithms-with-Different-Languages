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
    typename List<T>::Iterator List<T>::findSequential(const T &keyItem)
    {
        List<T>::ListNode *desiredNode = endNode;
        for (List<T>::ListNode *nodeIter = head; nodeIter != endNode; nodeIter = nodeIter->getNext())
        {
            if (nodeIter->getDataConst() == keyItem)
            {
                desiredNode = nodeIter;
                break;
            }
        }
        return List<T>::Iterator(desiredNode);
    }

    template <typename T>
    typename List<T>::Iterator List<T>::findBinary(const T &keyItem)
    {
        if (length == 0)
            return end();
        if (length == 1)
        {
            if (head->getDataConst() == keyItem)
                return begin();
            else
                return end();
        }
        int minIndex = 0;
        int maxIndex = length - 1;
        while (minIndex <= maxIndex)
        {
            int midIndex = ceil(static_cast<double>(minIndex + maxIndex) / 2);
            List<T>::ListNode *midNode = getNodeByIndex(midIndex);
            if (midNode->getDataConst() == keyItem)
            {
                List<T>::Iterator iter(midNode);
                return iter;
            }
            else if (keyItem < midNode->getDataConst())
                maxIndex = midIndex - 1;
            else
                minIndex = midIndex + 1;
        }
        /*
        if (list == nullptr || length == 0)
            return -1;
        if (length == 1)
        {
            if (list[0] == key)
                return 0;
            else
                return -1;
        }
        int minIndex = 0;
        int maxIndex = length - 1;
        while (minIndex <= maxIndex)
        {
            int midIndex = ceil(static_cast<double>((minIndex + maxIndex)) / 2);
            if (list[midIndex] == key)
                return midIndex;
            else if (key < list[midIndex])
                maxIndex = midIndex - 1;
            else
                minIndex = midIndex + 1;
        }
        return -1;
        */
        return end();
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
    void List<T>::swap(const typename List<T>::Iterator &iter1,
                       const typename List<T>::Iterator &iter2)
    {
        List<T>::ListNode *node1 = iter1.getNode();
        List<T>::ListNode *node2 = iter2.getNode();
        if (node1 == endNode || node2 == endNode)
            return;

        T temp = node1->getData();
        node1->setData(node2->getData());
        node2->setData(temp);
    }

    template <typename T>
    void List<T>::sortInsertionSort()
    {
        if (length == 0 || length == 1)
            return;
        //Start from the second element.
        List<T>::ListNode *nodeIter = head->getNext();
        for (; nodeIter != endNode; nodeIter = nodeIter->getNext())
        {
            List<T>::ListNode *holeNode = nodeIter;
            while ((holeNode != head) &&
             (holeNode->getDataConst() 
            < holeNode->getPrevious()->getDataConst()))
            {
                swap(holeNode, holeNode->getPrevious());
                holeNode = holeNode->getPrevious();
            }
        }
    }

    template <typename T>
    void List<T>::sortBubbleSort()
    {
        if (length == 0 || length == 1)
            return;
        bool isSorted = false;
        while (!isSorted)
        {
            isSorted = true;
            List<T>::ListNode *nodeIter = head;
            for (; nodeIter != tail; nodeIter = nodeIter->getNext())
            {
                if (nodeIter->getDataConst()
                  > nodeIter->getNext()->getDataConst())
                {
                    swap(nodeIter, nodeIter->getNext());
                    isSorted = false;
                }
            }
        }    
    }

    template <typename T>
    void List<T>::sortMergeSort()
    {
        if (length == 0 || length == 1)
            return;
        *this = mergeSortUtil(*this, 0, length - 1);
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
    typename List<T>::ListNode *List<T>::getNodeByIndex(int index) const
    {
        //The function assumes that the index is always a valid value
        //since the function is private and only called from within the
        //list class.
        int midIndex = ceil(static_cast<double>(length) / 2);
        if (index < midIndex) //First half.
        {
            List<T>::ListNode *nodeIter = head;
            for (int i = 0; i < index; i++)
            {
                nodeIter = nodeIter->getNext();
            }
            return nodeIter;
        }
        else //Second half.
        {
            List<T>::ListNode *nodeIter = tail;
            for (int i = length - 1; i > index; i--)
            {
                nodeIter = nodeIter->getPrevious();
            }
            return nodeIter;
        }
    }

    template <typename T>
    void List<T>::swap(const typename List<T>::ListNode &node1,
                       const typename List<T>::ListNode &node2)
    {
        T temp = node1->getDataConst();
        node1->setData(node2->getData());
        node2->setData(temp);
    }

    template <typename T>
    List<T> List<T>::mergeSortUtil(const List<T> &list, int minIndex, int maxIndex) const
    {
        if (minIndex == maxIndex)
        {
            List<T> oneElementList;
            oneElementList.pushBack(list.getNodeByIndex(minIndex)->getDataConst());
            return oneElementList;
        }
        else
        {
            //The static cast to double is to force the mid element to be always
            //the first element in the second half similar to the binary search work.
            //Doing it the other way is fine but I prefered it this way for consistency.
            int midIndex = ceil(static_cast<double>(minIndex + maxIndex) / 2);
            //First half.
            //When length is even, it will be length / 2
            //When length is odd, it will be length /2 integer division
            //in other words, smaller than the second half by 1.
            List<T> sortedList1 = mergeSortUtil(list, minIndex, midIndex - 1);
            //Second half.
            //When length is even, it will be length / 2
            //When length is odd, it will be ceil (length / 2)
            //in other words, bigger than the first half by 1.
            List<T> sortedList2 = mergeSortUtil(list, midIndex, maxIndex);
            List<T> sortedGroupList = merge(sortedList1, sortedList2);
            return sortedGroupList;
        }
    }

    template <typename T>
    List<T> List<T>::merge(const List<T> &list1, const List<T> &list2) const
    {
        List<T> groupList;
        List<T>::ListNode *nodeIter1 = list1.head;
        List<T>::ListNode *nodeIter2 = list2.head;
        while ((nodeIter1 != list1.endNode) && (nodeIter2 != list2.endNode))
        {
            if (nodeIter1->getDataConst() <= nodeIter2->getDataConst())
            {
                groupList.pushBack(nodeIter1->getDataConst());
                nodeIter1 = nodeIter1->getNext();
            }
            else
            {
                groupList.pushBack(nodeIter2->getDataConst());
                nodeIter2 = nodeIter2->getNext();
            }
        }

        while (nodeIter1 != list1.endNode)
        {
            groupList.pushBack(nodeIter1->getDataConst());
            nodeIter1 = nodeIter1->getNext();
        }
        while (nodeIter2 != list2.endNode)
        {
            groupList.pushBack(nodeIter2->getDataConst());
            nodeIter2 = nodeIter2->getNext();
        }
        return groupList;
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