//Vector data structure, part of the datastructures_mounir namepsace.
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

namespace datastructures_mounir
{
    template <typename T> class Vector;

    template <typename T> 
    std::ostream& operator<<( std::ostream&, const Vector<T> &vector);
    template <typename T> 
    bool operator ==(const Vector<T> &vector1, const Vector<T> &vector2);

    template <typename T>
    class Vector
    {
    public:
        //The default constructor does not allocate any dynamic memory.
        Vector();
        //Allocates dynamic memory to accumlate the given capacity, the default
        //constructor must be defined for the datatype given.
        Vector(int initialCapacity);
        //Copy constructor, deep copy the parameter vector in vector.
        //Relies on the assignment operator for the given type.
        Vector(const Vector<T> &otherVector);
        ~Vector();
        //Assignment operator, deep copy the parameter vector in vector.
        //Relies on the assignment operator for the given type.
        Vector<T> &operator =(const Vector<T> &otherVector);
        //Expand the vector the new capacity, if the new capacity
        //is lower of equal to the current capacity, nothing happens.
        void reserve(int newCapacity);
        //Clears (destroyes) all the elements in the array.
        //Both the length and the capacity is reset to zero
        //after function end.
        void clear();
        int getCapacity() const;
        int getLength() const;
        bool isEmpty() const;
        //Does not check for out of boundary access, use
        //at your own risk.
        T &operator [](int index) const;
        //Safer version of the operator function, throws
        //exception when attempting to access out of boundary element.
        T &at(int index) const;
        T &front() const;
        T &back() const;
        //Returns the index of the new inserted element, will
        //return -1 in case of failure.
        int insert(int index, const T &item);
        //Inserts the element at the end of the vector, returns the index
        //of the newly inserted element.
        int pushBack(const T &item);
        //Returns true if the deletion was successful, false
        //otherwise.
        bool erase(int index);
        friend bool operator == <T>(const Vector<T> &vector1, const Vector<T> &vector2);
        friend std::ostream& operator<< <T>(std::ostream&, const Vector<T> &vector);
    private:
        T *array;
        int capacity;
        int length;
        const int DEFAULT_EMPTY_EXPAND_CAPACITY = 10;
        void copyArray(T *oldArray, T *newArray, int length) const;
        //Relies on the usage of the assignment operator for the datatype
        //given for the vector.
    };
}

#endif