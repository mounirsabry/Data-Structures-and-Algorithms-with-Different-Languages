//The implementation file for the stack.h file.
#ifndef STACK_CPP
#define STACK_CPP

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

    template <typename T>
    bool operator== (const Stack<T> &stack1, const Stack<T> &stack2)
    {
        if (stack1.getLength() != stack2.getLength())
            return false;
        return stack1.list == stack2.list;
    }
}

#endif