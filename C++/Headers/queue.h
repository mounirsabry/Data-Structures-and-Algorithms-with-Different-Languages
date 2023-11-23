//Queue data structure, part of the datastructures_mounir namepsace.
#ifndef QUEUE_H
#define QUEUE_H

namespace datastructures_mounir
{
    template <typename T>
    class Queue
    {
    public:
        Queue();
        Queue(const Queue<T> &otherQueue);
        ~Queue();
        Queue<T> &operator =(const Queue<T> &otherQueue);
        void clear();
        int getLength() const;
        bool isEmpty() const;
        T &front() const;
        T &back() const;
        void pushBack(const T &item);
        void popFront();
    private:
        List<T> list;
    };
}

#endif