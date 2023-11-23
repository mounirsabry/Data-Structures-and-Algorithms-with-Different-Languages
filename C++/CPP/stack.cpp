//The implementation file for the stack.h file.
#ifndef STACK_CPP
#define STACK_CPP

#include <cstdlib> //For NULL.
#include <iostream>
#include "../Headers/stack.h"

namespace datastructures_mounir
{
    template <typename T>
    Stack<T>::Stack()
        :list()
    {}

    template <typename T>
    Stack<T>::Stack(const Stack &otherStack)
        :list(otherStack.list)
    {}
    template <typename T>
    Stack<T>::~Stack()
    {
        clear();
    }

    template <typename T>
    Stack<T> &Stack<T>::operator= (const Stack<T> &otherStack)
    {
        if (this != &otherStack)
            list = otherStack.list;
        return *this;
    }

    template <typename T>
    void Stack<T>::clear()
    {
        list.clear();
    }

    template <typename T>
    int Stack<T>::getLength() const
    {
        return list.getLength();
    }

    template <typename T>
    bool Stack<T>::isEmpty() const
    {
        return list.isEmpty();
    }

    template <typename T>
    T &Stack<T>::top() const
    {
        return list.back();
    }

    template <typename T>
    T Stack<T>::topConst() const
    {
        return list.back();
    }

    template <typename T>
    void Stack<T>::push(const T &item)
    {
        list.pushBack(item);
    }

    template <typename T>
    void Stack<T>::pop()
    {
        list.popBack();
    }
}

#endif