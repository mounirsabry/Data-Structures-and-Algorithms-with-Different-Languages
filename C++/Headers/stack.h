//Stack data structure, part of the datastructures_mounir namepsace.
#ifndef STACK_H
#define STACK_H

namespace datastructures_mounir
{
    template <typename T> class Stack;
    template <typename T>
    bool operator== (const Stack<T> &stack1, const Stack<T> &stack2);

    template <typename T>
    class Stack
    {
    public:
        Stack();
        Stack(const Stack<T> &otherStack);
        ~Stack();
        Stack<T> &operator =(const Stack<T> &otherStack);
        void clear();
        int getLength() const;
        bool isEmpty() const;
        T &top() const;
        T topConst() const;
        void push(const T &item);
        void pop();
        friend bool operator== <T>(const Stack<T> &stack1, const Stack<T> &stack2);
    private:
        List<T> list;
    };
}

#endif