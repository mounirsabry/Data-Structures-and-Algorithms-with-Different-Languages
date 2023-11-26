//The implementation file for the queue.h file.
#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "../Headers/queue.h"

namespace datastructures_mounir
{
    template <typename T>
    Queue<T>::Queue()
        :list()
    {}

    template <typename T>
    Queue<T>::Queue(const Queue<T> &otherQueue)
        :list(otherQueue.list)
    {}

    template <typename T>
    Queue<T>::~Queue()
    {
        clear();
    }

    template <typename T>
    Queue<T> &Queue<T>::operator =(const Queue<T> &otherQueue)
    {
        if (this != &otherQueue)
            list = otherQueue.list;
        return *this;
    }

    template <typename T>
    void Queue<T>::clear()
    {
        list.clear();
    }
    
    template <typename T>
    int Queue<T>::getLength() const
    {
        return list.getLength();
    }

    template <typename T>
    bool Queue<T>::isEmpty() const
    {
        return list.isEmpty();
    }

    template <typename T>
    T &Queue<T>::front() const
    {
        return list.front();
    }

    template <typename T>
    T &Queue<T>::back() const
    {
        return list.back();
    }

    template <typename T>
    void Queue<T>::pushBack(const T &item)
    {
        list.pushBack(item);
    }

    template <typename T>
    void Queue<T>::popFront()
    {
        list.popFront();
    }

    template <typename T>
    bool operator== (const Queue<T> &queue1, const Queue<T> &queue2)
    {
        if (queue1.getLength() != queue1.getLength())
            return false;
        return queue1.list == queue2.list;
    }
}

#endif