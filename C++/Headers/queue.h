//Queue data structure, part of the datastructures_mounir namepsace.
#ifndef QUEUE_H
#define QUEUE_H

namespace datastructures_mounir
{
    template <typename T> class Queue;
    template <typename T>
    bool operator== (const Queue<T> &queue1, const Queue<T> &queue2);

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
        friend bool operator== <T>(const Queue<T> &queue1, const Queue<T> &queue2);
    private:
        List<T> list;
    };
}

#endif